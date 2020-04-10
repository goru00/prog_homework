#include<iostream>
using namespace std;
class Node
{
private:
	int data;
public:
	Node* left, * right;
	Node(int data)
	{
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
	int getData() { return data; }
};
class Tree
{
private:
	Node* root;
	static void DeleteNode(Node*);
public:
	Tree()
	{
		root = 0;
	}
	~Tree()
	{
		DeleteNode(root);
	}
	Node* getRoot() { return root; }
	void Insert(int);
	void Show(Node*);
};
void Tree::DeleteNode(Node* n)
{
	if (n) {
		DeleteNode(n->left);
		DeleteNode(n->right);
		delete n;
	}
}
void Tree::Insert(int data)
{
	Node** temp = &root;
	while (*temp)
	{
		Node& node = **temp;
		if (data < node.getData()) {
			temp = &node.left;
		}
		else if (data > node.getData()) {
			temp = &node.right;
		}
		else return;
	}
	*temp = new Node(data);
}
void Tree::Show(Node* node)
{
	if (node != NULL) {
		Show(node->left);
		cout << node->getData() << endl;
		Show(node->right);
	}
}
int main()
{
	const int n = 6;
	int mass[n] = { 5,6,5,4,5,7 };
	Tree* tree1 = new Tree();	
	for (int i = 0; i < n; i++)
	{
		tree1->Insert(mass[i]);
	}
	tree1->Show(tree1->getRoot());
	//if (tree1->Find(4) == NULL) cout << "4 не найден";
	//else cout << "4 найден";
	return 0;
}