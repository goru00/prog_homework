#include<iostream>
#include<string>
#include <algorithm> // дабы не писать огромные тернарные условия, проще использовать функцию max
using namespace std;
template<class T>
class Tree
{
public:
	template<class Data>
	class Node
	{
	public:
		T data;
		Node<T>* left, * right;
		int height;
		Node(T data = T())
		{
			this->data = data;
			right = left = NULL;
			height = 0;
		}
	};
	Tree()
	{
		root = NULL;
	}
	~Tree()
	{

	}
	Node<T>* GetRoot() { return root; }
	int Height(Node<T>*);
	Node<T>* LeftRotate(Node<T>* n)
	{
		Node<T>* child = n->right->left, * parent = n->right;
		n->right->left = n;
		n->right = child;
		n->height = max(Height(n->left), Height(n->right)) + 1;
		if (n->right != NULL) n->right->height = max(Height(n->right->left), Height(n->right->right)) + 1;
		return parent;
	}
	Node<T>* RightRotate(Node<T>* n)
	{
		Node<T>* child = n->left->right, * parent = n->left;
		n->left->right = n;
		n->left = child;
		n->height = max(Height(n->left), Height(n->right)) + 1;
		if (n->left != NULL) n->left->height = max(Height(n->left->left), Height(n->left->right)) + 1;
		return parent;
	}
	Node<T>* LeftRightRotate(Node<T>* n)
	{
		n->left = LeftRotate(n->left);
		return RightRotate(n);
	}
	Node<T>* RightLeftRotate(Node<T>* n)
	{
		n->right = RightRotate(n->right);
		return LeftRotate(n);
	}
	void Insert(T data) { root = Insert(root, data); }
	Node<T>* Insert(Node<T>* n, T data) // доавбление элемента с последующей балансировкой дерева
	{
		if (n == NULL) return n = new Node<T>(data);
		else
		{
			if (data == n->data) return n;
			else if (data < n->data) n->left = Insert(n->left, data);
			else n->right = Insert(n->right, data);
		}
		if (Height(n->left) - Height(n->right) == 2)
		{
			if (data < n->left->data) n = RightRotate(n);
			else n = LeftRightRotate(n);
		}
		else if (Height(n->left) - Height(n->right) == -2)
		{
			if (data > n->right->data) n = LeftRotate(n);
			else n = RightLeftRotate(n);
		}
		n->height = max(Height(n->left), Height(n->right)) + 1;
		return n;
	}
	bool Delete(T data)
	{
		bool flag = false; // проверка на удаление
		root = Delete(flag, data, root);
		return flag;
	}
	Node<T>* Delete(bool& flag, T data, Node<T>* n)
	{
		if (n == NULL) return NULL;
		else
		{
			if (data == n->data)
			{
				if (n->right == NULL)
				{
					Node<T>* temp = n;
					n = n->left;
					delete temp;
					flag = true;
					return n;
				}
				else
				{
					Node<T>* temp = n->right;
					while (temp->left != NULL) temp = temp->left;
					n->data = temp->data;
					n->right = Delete(flag, temp->data, n->right);
				}
			}
			else if (data < n->data) n->left = Delete(flag, data, n->left);
			else n->right = Delete(flag, data, n->right);
			if (Height(n->left) - Height(n->right) == 2)
			{
				if (data < n->left->data) n = RightRotate(n);
				else n = LeftRightRotate(n);
			}
			else if (Height(n->left) - Height(n->right) == -2)
			{
				if (data > n->right->data) n = LeftRotate(n);
				else n = RightLeftRotate(n);
			}
			n->height = max(Height(n->left), Height(n->right)) + 1;
		}
		return n;
	}
	bool Search(T data)
	{
		return (Search(data, root) == NULL) ? false : true;
	}
	Node<T>* Search(T data, Node<T>* n)
	{
		if (n == NULL) return NULL;
		else if (data == n->data) return n;
		else if (data < n->data) return Search(data, n->left);
		return Search(data, n->right);
	}
	bool Update(T n_data, T o_data)
	{
		if (Delete(o_data))
		{
			Insert(n_data);
			return true;
		}
		return false;
	}
	void Show()
	{
		Show(root);
	}
	void Show(Node<T>* n)
	{
		if (n == NULL) return;
		Show(n->left);
		cout << n->data << " " << n->height << endl;
		Show(n->right);
	}
	bool Empty() { return root == NULL; }
private:
	Node<T>* root;
};
template<class T>
int Tree<T>::Height(Node<T>* n)
{
	return n == NULL ? -1 : n->height;
}
class Data
{
private:
	int num; // значение узла
	string side; // направление, которое принимает узел
public:
	Data() : num(0), side("") { }
	Data(int num, string side)
	{
		this->num = num;
		this->side = side;
	}
	friend bool operator<(const Data& arg1, const Data& arg2)
	{
		return (arg1.num < arg2.num);
	}
	friend bool operator>(const Data& arg1, const Data& arg2)
	{
		return (arg1.num > arg2.num);
	}
	friend bool operator==(const Data& arg1, const Data& arg2)
	{
		return (arg1.num == arg2.num);
	}
	friend ostream& operator<<(ostream& out, const Data& arg)
	{
		out << arg.num << " " << arg.side;
		return out;
	}
};
int main()
{
	setlocale(0, "");
	const int n = 5;
	// здесь side нужен был для тестирования правильности работы алгоритма
	Data tab[] = {
		{10, "left"},
		{5, "middle"},
		{3, "left"},
		{11, "right"},
		{12, "right"}
	};
	Tree<Data>* tree1 = new Tree<Data>();
	for (int i = 0; i < n; i++)
	{
		tree1->Insert(tab[i]);
	}
	if (tree1->Empty()) cout << "Дерево пустое." << endl;
	else tree1->Show(); // обход дерева
	Data elem = { 3, "left" };
	if (tree1->Search(elem)) cout << "Элемент найден" << endl;
	else cout << "Элемент не найден" << endl;
	cout << "Удалим элемент" << endl;
	if (tree1->Delete(elem)) cout << "Элемент удален" << endl;
	else cout << "Элемент не найден" << endl;
	if (tree1->Empty()) cout << "Дерево пустое." << endl;
	else tree1->Show(); // обход дерева
	elem = { 11, "right" };
	if (tree1->Delete(elem)) cout << "Элемент удален" << endl;
	else cout << "Элемент не найден" << endl;
	if (tree1->Empty()) cout << "Дерево пустое." << endl;
	else tree1->Show(); // обход дерева
	Data o_elem = { 12, "middle" };
	Data n_elem = { 8, "left" };  
	if (tree1->Update(n_elem, o_elem))
	{
		cout << "Элемент обновлен\n";
		tree1->Show();
	}
	else cout << "Элемент не найден\n";
	return 0;
}