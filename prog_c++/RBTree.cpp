#include<iostream>
#include<string>

using namespace std;

template<class T>
class RBTree
{
public: 
	template<class T>
	class Node
	{
	public:
		T data;
		Node* left, * right, * p;
		string color;
		Node(T data = T())
		{
			this->data = data;
			left = right = p = NULL;
			color = "R";
		}
	};
	RBTree()
	{
		root = NULL;
	}
	string checkColor(Node<T>* n)
	{
		if (n == NULL) return "B";
		return n->color;
	}
	void insert(T data)
	{
		Node<T>* n = new Node<T>(data);
		root = insertBST(root, n);
		fixInsert(n);
	}
	void del(T data) {
		Node<T>* n = deleteBST(root, data);
		fixDelete(n);
	}
	bool update(T oldData, T newData)
	{
		if (find(oldData)) {
			del(oldData);
			insert(newData);
			return true;
		}
		return false;
	}
	Node<T>* find(T data)
	{
		Node<T>* temp = root;
		while (temp != NULL) {
			if (data < temp->data) {
				temp = temp->left;
			}
			else if (data > temp->data) {
				temp = temp->right;
			}
			else {
				break;
			}
		}
		return temp;
	}
	void show()
	{
		show(root);
	}
	void show(Node<T>* n) {
		if (n) {
			show(n->left);
			cout << n->data << endl;
			show(n->right);
		}
	}
private:
	Node<T>* root;
	Node<T>* minValueNode(Node<T>* n)
	{
		Node<T>* tmp = n;
		while (tmp->left != NULL) {
			tmp = tmp->left;
		}
		return tmp;
	}
	Node<T>* maxValueNode(Node<T>* n)
	{
		Node<T>* tmp = n;
		while (tmp->right != NULL) {
			tmp = tmp->right;
		}
		return tmp;
	}
	Node<T>* deleteBST(Node<T>* m, T data)
	{
		if (m == NULL) {
			return root;
		}
		if (data < m->data) return deleteBST(m->left, data);
		if (data > m->data) return deleteBST(m->right, data);
		if (m->left == NULL || m->right == NULL) return m;
		Node<T>* temp = minValueNode(m->right);
		m->data = temp->data;
		return deleteBST(m->right, temp->data);
	}
	void rotateLeft(Node<T>* n) {
		Node<T>* nRight = n->right;
		n->right = nRight->left;
		if (n->right != NULL) {
			n->right->p = n;
		}
		nRight->p = n->p;
		if (n->p == NULL) {
			root = nRight;
		}
		else if (n == n->p->left) {
			n->p->left = nRight;
		}
		else {
			n->p->right = nRight;
		}
		nRight->left = n;
		n->p = nRight;
	}
	void rotateRight(Node<T>* n) {
		Node<T>* nLeft = n->left;
		n->left = nLeft->right;
		if (n->left != NULL) {
			n->left->p = n;
		}
		nLeft->p = n->p;
		if (n->p == NULL) {
			root = nLeft;
		}
		else if (n == n->p->left) {
			n->p->left = nLeft;
		}
		else {
			n->p->right = nLeft;
		}
		nLeft->right = n;
		n->p = nLeft;
	}
	void setColor(Node<T>* n, string c)
	{
		if (n == NULL) return;
		n->color = c;
	}
	Node<T>* insertBST(Node<T>* m, Node<T>* n) {
		if (m == NULL) return n;
		if (n->data < m->data) {
			m->left = insertBST(m->left, n);
			m->left->p = m;
		}
		else if (n->data > m->data) {
			m->right = insertBST(m->right, n);
			m->right->p = m;
		}
		return m;
	}
	void fixDelete(Node<T>* n) {
		if (n == NULL) return;
		if (n == root) {
			root = NULL;
			return;
		}
		if (checkColor(n) == "R" || checkColor(n->left) == "R" || checkColor(n->right) == "R") {
			Node<T>* child;
			if (n->left != NULL) {
				child = n->left;
			}
			else child = n->right;
			if (n == n->p->left) {
				n->p->left = child;
				if (child != NULL) {
					child->p = n->p;
				}
				setColor(child, "B");
				delete n;
			}
			else {
				n->p->right = child;
				if (child != NULL) {
					child->p = n->p;
				}
				setColor(child, "B");
				delete n;
			}
		}
		else {
			Node<T>* sub = NULL;
			Node<T>* parent = NULL;
			Node<T>* ptr = n;
			setColor(ptr, "BB");
			while (ptr != root && checkColor(ptr) == "BB") {
				parent = ptr->p;
				if (ptr == parent->left) {
					sub = parent->right;
					if (checkColor(sub) == "R") {
						setColor(sub, "B");
						setColor(parent, "R");
						rotateLeft(parent);
					}
					else {
						if (checkColor(sub->left) == "B" && checkColor(sub->right) == "B") {
							setColor(sub, "R");
							if (checkColor(parent) == "R") {
								setColor(parent, "B");
							}
							else {
								setColor(parent, "BB");
							}
						}
						else {
							if (checkColor(sub->right) == "B") {
								setColor(sub->left, "B");
								setColor(sub, "R");
								rotateRight(sub);
								sub = parent->right;
							}
							setColor(sub, parent->color);
							setColor(parent, "B");
							setColor(sub->right, "B");
							rotateLeft(parent);
							break;
						}
					}
				}
				else {
					sub = parent->left;
					if (checkColor(sub) == "R") {
						setColor(sub, "B");
						setColor(parent, "R");
						rotateRight(parent);
					}
					else {
						if (checkColor(sub->left) == "B" && checkColor(sub->right) == "B") {
							setColor(sub, "R");
							if (checkColor(parent) == "R") {
								setColor(parent, "B");
							}
							else {
								setColor(parent, "BB");
							}
							ptr = parent;
						}
						else {
							if (checkColor(sub->left) == "B") {
								setColor(sub->right, "B");
								setColor(sub, "R");
								rotateLeft(sub);
								sub = parent->left;
							}
							setColor(sub, parent->color);
							setColor(parent, "B");
							setColor(sub->left, "B");
							rotateRight(parent);
							break;
						}
					}
				}
			}
			if (n == n->p->left) n->p->left = NULL;
			else n->p->right = NULL;
			delete n;
			setColor(root, "B");
		}
	}
	void fixInsert(Node<T>* n)
	{
		Node<T>* nParent = NULL;
		Node<T>* gParent = NULL;
		while (n != root && checkColor(n) == "R" && checkColor(n->p) == "R") {
			nParent = n->p;
			gParent = nParent->p;
			if (nParent == gParent->left) {
				Node<T>* un = gParent->right;
				if (checkColor(un) == "R") {
					setColor(un, "B");
					setColor(nParent, "B");
					setColor(gParent, "R");
					n = gParent;
				}
				else {
					if (n == nParent->right) {
						rotateLeft(nParent);
						n = nParent;
						nParent = n->p;
					}
					rotateRight(gParent);
					string s = nParent->color;
					nParent->color = gParent->color;
					gParent->color = s;
					n = nParent;
				}
			}
			else {
				Node<T>* un = gParent->left;
				if (checkColor(un) == "R") {
					setColor(un, "B");
					setColor(nParent, "B");
					setColor(gParent, "R");
					n = gParent;
				}
				else {
					if (n == nParent->left) {
						rotateRight(nParent);
						n = nParent;
						nParent = n->p;
					}
					rotateLeft(gParent);
					string s = nParent->color;
					nParent->color = gParent->color;
					gParent->color = s;
					n = nParent;
				}
			}
		}
		setColor(root, "B");
	}
};

class Data
{
private:
	int numTicket;
	string name;
	string phone;
	string numGroup;
public:
	Data()
	{
		this->numTicket = 0;
		this->name = "";
		this->phone = "";
		this->numGroup = "";
	}
	Data(int numTicket, string name, string phone, string numGroup)
	{
		this->numTicket = numTicket;
		this->name = name;
		this->phone = phone;
		this->numGroup = numGroup;
	}
	friend bool operator==(const Data&, const Data&);
	friend bool operator!=(const Data&, const Data&);
	friend bool operator>(const Data&, const Data&);
	friend bool operator<(const Data&, const Data&);
	friend ostream& operator<<(ostream&, const Data&);
};

bool operator==(const Data& arg1, const Data& arg2)
{
	return (arg1.name == arg2.name && arg1.numGroup == arg2.numGroup) || (arg1.numTicket == arg2.numTicket && arg1.name == arg2.name);
}

bool operator!=(const Data& arg1, const Data& arg2)
{
	return (arg1.name != arg2.name) && (arg1.numGroup != arg2.numGroup);
}

bool operator>(const Data& arg1, const Data& arg2)
{
	return (arg1.name > arg2.name) || (arg1.name == arg2.name) && (arg1.numGroup > arg2.numGroup);
}

bool operator<(const Data& arg1, const Data& arg2)
{
	return (arg1.name < arg2.name) || (arg1.name == arg2.name) && (arg1.numGroup < arg2.numGroup);
}

ostream& operator<<(ostream& out, const Data& arg)
{
	out.width(16);
	out << left << arg.numTicket;
	out.width(32);
	out << left << arg.name;
	out.width(24);
	out << left << arg.phone;
	out.width(18);
	out << left << arg.numGroup;
	return out;
}

int main() {
	setlocale(0, "");
	const int n = 10;
	Data tab[n] = {
		Data(1125, "Федин Артем Степанович", "8-912-546-18-21", "ИВТ-31"),
		Data(1307, "Арсентьева Любовь Михайловна", "8-965-872-31-27", "БУ-21"),
		Data(2904, "Фролова Ирина Юрьевна", "8-495-653-56-65", "ИВТ-21"),
		Data(3009, "Бендер Остап Ибрагомович", "8-687-548-78-54", "ИВТ-21"),
		Data(3127, "Иванов Петр Николаевич", "8-359-956-45-88", "БУ-11"),
		Data(4003, "Фролова Ирина Юрьевна", "8-954-875-43-24", "ГМУ-11"),
		Data(1321, "Бендер Остап Ибрагомович", "8-324-435-23-43", "ГМУ-11"),
		Data(2396, "Иванов Петр Николаевич", "8-547-657-48-11", "ИВТ-21"),
		Data(3321, "Федин Артем Степанович", "8-673-657-36-34", "БУ-21"),
		Data(4021, "Арсентьева Любовь Михайловна", "8-954-234-56-56", "ИВТ-31")
	};
	RBTree<Data>* tree = new RBTree<Data>();
	for (int i = 0; i < n; i++) {
		tree->insert(tab[i]);
	}
	tree->show();
	cout << "Удалим запись 6 (в исх.таблице): " << endl;
	tree->del({ 4003, "Фролова Ирина Юрьевна", "8-954-875-43-24", "ГМУ-11" });
	cout << "Произведем замену 2-ой записи: " << endl;
	Data change = { 1307, "Яковлева Любовь Михайловна", "8-965-872-31-27", "БУ-21" };
	if (tree->update(tab[1], change)) cout << "Запись успешно обновлена." << endl;
	else cout << "Запись для замены была не найдена" << endl;
	tree->show();
	return 0;
}