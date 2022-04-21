#include<iostream>
#include<string>

template<typename T>
class Hash
{
private:
	int SIZE;
	template<typename P>
	class Tree
	{
	private:
		template<typename U>
		class Node
		{
		public:
			T data;
			Node* right, * left;
			Node(T data = T()) {
				this->data = data;
				right = left = nullptr;
			}
		};
		Node<T>* root;
	public:
		Tree() {
			root = nullptr;
		}
		void insert(T data) {
			root = insert(root, data);
		}
		Node<T>* insert(Node<T>* node, T data)
		{
			if (node == nullptr) {
				return new Node<T>(data);
			}
			if (data < node->data) {
				node->left = insert(node->left, data);
			}
			else if (data > node->data) {
				node->right = insert(node->right, data);
			}
			return node;
		}
		void showTree() {
			showTree(root);
		}
		void showTree(Node<T>* node) {
			if (node != nullptr) {
				showTree(node->left);
				std::cout << " --> " << node->data;
				showTree(node->right);
			}
		}
	};
	int checkPrime(int n) {
		if (n == 1 || n == 0) {
			return 0;
		}
		for (int i = 2; i < n / 2; i++) {
			if (n % i == 0) {
				return 0;
			}
		}
		return 1;
	}
	int getPrime(int n) {
		if (n % 2 == 0) {
			n++;
		}
		while (!checkPrime(n)) {
			n = n + 2;
		}
		return n;
	}
	int hashFunction(T key) {
		return key % SIZE;
	}
	Tree<T>* blocks;
public:
	Hash(int size)
	{
		this->SIZE = getPrime(size);
		blocks = new Tree<T>[SIZE];
	}
	void insert(T data) {
		int index = hashFunction(data);
		blocks[index].insert(data);
	}
	void show() {
		for (int index = 0; index < SIZE; index++) {
			std::cout << "ячейка[" << index << "]";
			blocks[index].showTree();
			std::cout << std::endl;
		}
	}
};

class Data
{
private:
	int id;
	std::string name;
	std::string direction;
	int price;
public:
	Data() : id(0), name(""), direction(""), price(0) {}
	Data(int id, std::string name, std::string direction, int price)
	{
		this->id = id;
		this->name = name;
		this->direction = direction;
		this->price = price;
	}
	friend bool operator<(const Data& a, const Data& b) {
		return (a.id < b.id) || (a.id == b.id) && (a.name < b.name);
	}
	friend bool operator>(const Data& a, const Data& b) {
		return (a.id > b.id) || (a.id == b.id) && (a.name > b.name);
	}
	friend int operator%(const Data& a, const int b) {
		if (b == 0) {
			throw std::runtime_error("zero division error");
		}
		return a.id % b;
	}
	friend std::ostream& operator<<(std::ostream& out, const Data& arg)
	{
		out << arg.id << " " << arg.name << " " << arg.direction << " " << arg.price;
		return out;
	}
};

int main() {
	setlocale(0, "");
	const int N = 6;
	Data mass[] = {
		Data(2345, "Иванов Сергей Степанович", "Разнорабочий", 28000),
		Data(2346, "Краснов Сергей Георгиевич", "Сантехник", 32000),
		Data(2347, "Бендер Остап Ибрагимович", "Директор", 62000),
		Data(2349, "Петров Сергей Степанович", "Электрик", 36000),
		Data(2356, "Кирпичев Владимир Викторович", "Начальник смены", 48000),
		Data(2378, "Абрамов Иван Петрович", "Электрик", 36000)
	};
	Hash<Data> table(N);
	for (int index = 0; index < N; index++) {
		table.insert(mass[index]);
	}
	table.show();
	return 0;
}