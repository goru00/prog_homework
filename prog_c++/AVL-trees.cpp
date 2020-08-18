#include<iostream>
#include<string>
using namespace std;
template<class T>
class Node
{
private:
	Node* left, * right;
	T data;
	int height;
public:
	Node(T data = T())
	{
		this->data = data;
		left = right = NULL;
		height = 1;
	}
	Node* GetLeft() { return left; }
	void SetLeft(Node* left) { this->left = left; }
	Node* GetRight() { return right; }
	void SetRight(Node* right) { this->right = right; }
	T GetData() { return data; }
	void SetData(T data) { this->data = data; }
	int GetHeight() { return height; }
	void SetHeight(int height) { this->height = height; }
};
template<class T>
class Tree
{
private:
	Node<T>* root;
public:
	Tree();
	~Tree();
	Node<T>* GetRoot() { return root; }
	bool Empty() { return root == NULL; }
	int Height(Node<T>*);
	int BFactor(Node<T>*);
	void FixHeight(Node<T>*);
	Node<T>* RotateRight(Node<T>*);
	Node<T>* RotateLeft(Node<T>*);
	Node<T>* Balance(Node<T>*);
	Node<T>* Insert(T);
	void Show();
	void Show(Node<T>*);
};
template<class T>
Tree<T>::Tree()
{
	root = NULL;
}
template<class T>
Tree<T>::~Tree()
{

}
template<class T>
int Tree<T>::Height(Node<T>* n)
{
	return n ? n->GetHeight() : 0;
}
template<class T>
int Tree<T>::BFactor(Node<T>* n)
{
	return Height(n->GetRight()) - Height(n->GetLeft());
}
template<class T>
void Tree<T>::FixHeight(Node<T>* n)
{
	int hl = Height(n->GetLeft());
	int hr = Height(n->GetRight());
	n->SetHeight((hl > hr ? hl : hr) + 1);
}
template<class T>
Node<T>* Tree<T>::RotateRight(Node<T>* n)
{
	Node<T>* temp = n->GetLeft();
	n->SetLeft(temp->GetRight());
	temp->SetRight(n);
	FixHeight(n);
	FixHeight(temp);
	return temp;
}
template<class T>
Node<T>* Tree<T>::RotateLeft(Node<T>* n)
{
	Node<T>* temp = n->GetRight();
	n->SetRight(temp->GetLeft());
	temp->SetLeft(n);
	FixHeight(n);
	FixHeight(temp);
	return temp;
}
template<class T>
Node<T>* Tree<T>::Balance(Node<T>* n)
{
	FixHeight(n);
	if (BFactor(n) == 2)
	{
		if (BFactor(n->GetRight()) < 0)
		{
			n->SetRight(RotateRight(n->GetRight()));
		}
		return RotateLeft(n);
	}
	if (BFactor(n) == -2)
	{
		if (BFactor(n->GetLeft()) < 0)
		{
			n->SetLeft(RotateLeft(n->GetLeft()));
		}
		return RotateRight(n);
	}
	return n;
}
template<class T>
Node<T>* Tree<T>::Insert(T data)
{
	if (root == NULL)
	{
		root = new Node<T>(data);
		return root;
	}
	Node<T>* current = root;
	while (true)
	{
		if (data < current->GetData())
		{
			if (current->GetLeft() == NULL)
			{
				current->SetLeft(new Node<T>(data));
				Balance(current);
				return current->GetLeft();
			}
			current = current->GetLeft();
		}
		else if (data > current->GetData())
		{
			if (current->GetRight() == NULL)
			{
				current->SetRight(new Node<T>(data));
				Balance(current);
				return current->GetRight();
			}
			current = current->GetRight();
		}
		else return NULL;
	}
}
template<class T>
void Tree<T>::Show()
{
	Show(root);
}
template<class T>
void Tree<T>::Show(Node<T>* n)
{
	if (n)
	{
		Show(n->GetLeft());
		cout << n->GetData() << n->GetHeight() << endl;
		Show(n->GetRight());
	}
}
class Data
{
private:
	int fname; string lname, street, org;
public:
	Data() : fname(0), lname(""), street(""), org("") { }
	Data(int fname, string lname, string street, string org)
	{
		this->fname = fname;
		this->lname = lname;
		this->street = street;
		this->org = org;
	}
	friend bool operator<(const Data&, const Data&);
	friend bool operator>(const Data&, const Data&);
	friend ostream& operator<<(ostream&, const Data&);
};
bool operator<(const Data& arg1, const Data& arg2)
{
	return (arg1.fname < arg2.fname);
}
bool operator>(const Data& arg1, const Data& arg2)
{
	return (arg1.fname > arg2.fname);
}
ostream& operator<<(ostream& out, const Data& arg)
{
	out << arg.fname << "\t" << arg.lname << "\t" << arg.street << "\t" << arg.org << endl;
	return out;
}
int main()
{
	setlocale(0, "");
	const int size = 6;
	Data tab[] = {
		{1006, "Иванов Алеша",    "2009-10-30", "Старшая"},
		{1002, "Сидорова Наташа", "2008-02-27", "Старшая"},
		{1001, "Петрова Катя",    "2009-09-17", "Старшая"},
		{1003, "Петров Артем",    "2006-07-23", "Младшая"},
		{1004, "Фролов Антон",    "2008-12-31", "Младшая"},
		{1005, "Федорова Ирина",  "2009-09-12", "Подготовительная"}
	};
	Data elem;
	Tree<Data>* tree1 = new Tree<Data>();
	for (int i = 0; i < size; i++)
	{
		tree1->Insert(tab[i]);
	}
	if (tree1->Empty()) cout << "Дерево пустое" << endl;
	else tree1->Show();
	return 0;
}