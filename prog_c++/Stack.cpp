#include<iostream>
#include<string>
#include<stdexcept>
#include<cassert>
using namespace std;
template<class T>
class Stack
{
public:
	template<class T>
	class Node
	{
	public:
		T data;
		Node<T>* pNext;
		Node(T data = T(), Node<T>* pNext = NULL)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	Stack();
	~Stack();
	void Push(T);
	void Pop();
	void Show();
	bool Empty();
	void Erase();
private:
	Node<T>* head;
	int size;
};
template<class T>
Stack<T>::Stack()
{
	head = NULL;
	size = 0;
}
template<class T>
Stack<T>::~Stack()
{
	Erase();
}
template<class T>
void Stack<T>::Push(T arg)
{
	Node<T>* temp = new Node<T>();
	temp->data = arg;
	temp->pNext = head;
	head = temp;
}
template<class T>
void Stack<T>::Pop()
{
	Node<T>* temp;
	temp = head;
	head = head->pNext;
	delete temp;
}
template<class T>
void Stack<T>::Show()
{
	Node<T>* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->pNext;
	}
}
template<class T>
bool Stack<T>::Empty()
{
	return head == NULL;
}
template<class T>
void Stack<T>::Erase()
{
	Node<T>* temp = head, * curr;
	while (temp != NULL)
	{
		curr = temp;
		temp = temp->pNext;
		delete curr;
	}
	head = NULL;
}
class Data
{
private:
	string name, org, street;
	int price;
public:
	Data() : name(""), org(""), street(""), price(0) { }
	Data(string name, string org, string street, int price)
	{
		this->name = name;
		this->org = org;
		this->street = street;
		this->price = price;
	}
	friend bool operator<(Data&, Data&);
	friend bool operator==(Data&, Data&);
	friend ostream& operator<<(ostream&, const Data&);
};
bool operator<(Data& arg1, Data& arg2)
{
	return (arg1.price < arg2.price) || ((arg1.price == arg2.price) && (arg1.name < arg2.name));
}
bool operator==(Data& arg1, Data& arg2)
{
	return (arg1.name == arg2.name);
}
// перегруженный оператор вывода
ostream& operator<<(ostream& out, const Data& obj)
{
	out << obj.name << "\t" << obj.org << "\t" << obj.street << "\t" << obj.price << endl;
	return out;
}
int main()
{
	setlocale(0, "");
	const int count = 4;
	Data tab[] = {
		{"Дима", "Дубна", "Орлова", 500},
		{"Федор", "Дубна", "Орлова", 1200},
		{"Юра", "Дубна", "Орлова", 700},
		{"Иван", "Дубна", "Орлова", 700}
	};
	Stack<Data>* stack = new Stack<Data>();
	for (int i = 0; i < count; i++)
	{
		stack->Push(tab[i]);
	}
	stack->Show();
	cout << endl;
	stack->Pop();
	stack->Show();
	stack->Erase();
	if (stack->Empty()) cout << "Стек пуст";
	return 0;
}