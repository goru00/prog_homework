#include<iostream>
#include<string>
#include<cassert>
using namespace std;
template<class T>
class Queue
{
private:
	T* mass;
	int size;
public:
	Queue()
	{
		size = 0;
		mass = NULL;
	}
	~Queue()
	{
		if (!Empty()) Erase();
	}
	void Push(T);
	void Pop();
	void Erase();
	void Show();
	bool Empty();
};
template<class T>
void Queue<T>::Push(T arg)
{
	T* m_mass;
	m_mass = mass;
	mass = new T[size + 1];
	for (int i = 0; i < size; i++) mass[i] = m_mass[i];
	mass[size] = arg;
	size++;
	delete[] m_mass;
}
template<class T>
void Queue<T>::Pop()
{
	T* m_mass;
	m_mass = new T[size - 1];
	size--;
	for (int i = 0; i < size; i++)
	{
		m_mass[i] = mass[i + 1];
	}
	delete[] mass;
	mass = m_mass;
}
template<class T>
void Queue<T>::Erase()
{
	delete[] mass;
	size = 0;
}
template<class T>
void Queue<T>::Show()
{
	for (int i = 0; i < size; i++)
	{
		cout << mass[i] << endl;
	}
}
template<class T>
bool Queue<T>::Empty()
{
	return size == 0;
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
	Queue<Data> mass;
	for (int i = 0; i < count; i++)
	{
		mass.Push(tab[i]);
	}
	mass.Show();
	cout << endl;
	mass.Pop();
	mass.Show();
	if (mass.Empty()) cout << "Очередь пуста\n";
	else mass.Erase();
	return 0;
}