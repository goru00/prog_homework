#include<iostream>
#include<string>
using namespace std;
template<class T>
class List
{
private:
	template<class T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data=T(), Node* pNext = NULL)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;
	Node<T>* head;
public:
	List();
	~List();
	int getSize() { return size; }
	void push_back(T);
	void push_front(T);
	void insert(T, int);
	void pop_front();
	void pop_back();
	void remove(int);
	void update(T, T);
	void sort();
	bool find(T);
	void clear();
	void show();
	bool empty();
	T& operator[](const int);
};
template<class T>
List<T>::List()
{
	size = 0;
	head = NULL;
}
template<class T>
List<T>::~List()
{
	clear();
}
// добавление. каждый новый элемент добавляется В КОНЕЦ списка
template<class T>
void List<T>::push_back(T data)
{
	if (head == NULL)
	{
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = head;
		while (current->pNext != NULL)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	size++;
}
// добавление. каждый новый элемент добавляется В НАЧАЛО списка
template<class T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
}
// добавление. каждый новый элемент добавляется по индексу, а другой элемент который стоял по этому индексу сдвигается к концу
template<class T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else {
		Node<T>* prev = head;
		for (int i = 0; i < index - 1; i++)
		{
			prev = prev->pNext;
		}
		Node<T>* newData = new Node<T>(data, prev->pNext);
		prev->pNext = newData;
		size++;
	}
}
// удаление первого элемента
// метод нужен для очистки списка(смотреть метод clear)
template<class T>
void List<T>::pop_front()
{
	Node<T>* current = head;
	head = head->pNext;
	delete current;
	size--;
}
// удаление последнего элемента с помощью метода remove
template<class T>
void List<T>::pop_back()
{
	remove(size - 1);
}
// удаление строки по индексу в списке
template<class T>
void List<T>::remove(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else {
		Node<T>* prev = head;
		for (int i = 0; i < index - 1; i++)
		{
			prev = prev->pNext;
		}
		Node<T>* toDelete = prev->pNext;
		prev->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
}
// обновление строки в списке
template<class T>
void List<T>::update(T item1, T item2)
{
	Node<T>* current = head;
	while (current)
	{
		if (current->data == item1) {
			current->data = item2;
			return;
		}
		current = current->pNext;
	}
	push_back(item2);
}
// метод сортировки списка
template<class T>
void List<T>::sort()
{
	Node<T>* prev = head;
	Node<T>* current = head->pNext;
	Node<T>* temp = new Node<T>();
	while (prev->pNext)
	{
		while (current)
		{
			if (prev->data < current->data) {
				temp->data = prev->data;
				prev->data = current->data;
				current->data = temp->data;
			}
			current = current->pNext;
		}
		prev = prev->pNext;
		current = prev->pNext;
	}
}
// метод поиска в списке по конкретной строке(может быть сделаю по индексу, но думаю, что это слишком просто)
template<class T>
bool List<T>::find(T item)
{
	Node<T>* current = head;
	while (current)
	{
		if (current->data == item) return true;
		else current = current->pNext;
	}
	return false;
}
// метод очистки списка
template<class T>
void List<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}
// просмотр
template<class T>
void List<T>::show()
{
	Node<T>* current = head;
	while (current)
	{
		cout << current->data << endl;
		current = current->pNext;
	}
}
// проверка на пустоту
template<class T>
bool List<T>::empty()
{
	return size != 0;
}
// оператор взятия индекса
template<class T>
T& List<T>::operator[](const int index)
{
	int count = 0;
	Node<T>* current = head;
	while (current)
	{
		if (count == index)
		{
			return current->data;
		}
		current = current->pNext;
		count++;
	}
}
// класс для хранения первоначальных данных
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
bool operator<(Data &arg1, Data &arg2)
{
	return (arg1.price < arg2.price) || ((arg1.price == arg2.price) && (arg1.name < arg2.name));
}
bool operator==(Data &arg1, Data &arg2)
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
	List<Data>* list = new List<Data>();
	// можно организовать отдельный метод класса List для "запуливания" элементов, но целесообразнее как по мне иниц.переменную size
	for (int i = 0; i < count; i++)
	{
		list->push_back(tab[i]);
	}
	list->show();
	cout << endl;
	cout << "Произведем очистку:" << endl;
	list->clear();
	if (list->empty()) list->show();
	else cout << "Список пустой" << endl;
	for (int i = 0; i < count; i++)
	{
		list->push_front(tab[i]);
	}
	list->show();
	cout << "Добавим элемент:" << endl;
	list->insert(tab[1], 2);
	list->show();
	cout << "Удалим этот элемент" << endl;
	list->remove(2);
	list->show();
	cout << "Удалим последний элемент" << endl;
	list->pop_back();
	list->show();
	cout << "Сортировка списка: " << endl;
	list->sort();
	list->show();
	cout << "Поиск строки по имени: " << endl;
	Data find_element = { "Иван", "Дубна", "Орлова", 700 };
	if (list->find(find_element)) cout << "Данная строка найдена" << endl;
	cout << "Обновление строки: " << endl;
	Data change = { "Никита", "Дубна", "Орлова", 700 };
	list->update(find_element, change);
	list->show();
	return 0;
}