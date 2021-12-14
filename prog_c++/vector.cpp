#include<iostream>
#include<string>

using namespace std;

template<class T>
class Vector
{
private:
	T* data;
	int size;
	int begin;
	int length;
	int index(int n) {
		n += begin;
		if (n >= size) n -= size;
		return n;
	}
	void newData() {
		T* oldData = data;
		data = new T[size * 2];
		for (int i = 0; i < length; i++) {
			data[i] = oldData[index(i)];
		}
		delete[] oldData;
		size *= 2;
		begin = 0;
	}
public:
	Vector() {
		size = 1;
		data = new T[size];
		begin = 0;
		length = 0;
	}
	~Vector() {
		delete[] data;
	}
	Vector(int size) {
		data = new T[size];
		this->size = size;
		begin = 0;
		length = 0;
	}
	Vector(int size, T item, int n) {
		data = new T[size];
		this->size = size;
		begin = 0;
		if (size < n) length = size;
		else length = n;
		for (int i = 0; i < length; i++) data[i] = item;
	}
	void pushBack(T item) {
		if (length == size) newData();
		data[index(length)] = item;
		length++;
	}
	T* popBack() {
		if (length == 0) return NULL;
		return data + index(length--);
	}
	void insert(T item) {
		if (length == size) newData();
		if (begin > 0) begin--;
		else begin = size - 1;
		length++;
		data[index(0)] = item;
	}
	T* erase(int n) {
		if (length == 0 || n < 0 || n >= length) return NULL;
		T* oldData = data + n;
		if (n <= length / 2) {
			for (int i = n; i > 0; i--) data[index(i)] = data[index(i - 1)];
			if (++begin == size) begin = 0;
		}
		else {
			for (int i = n; i < length - 1; i++) data[index(i)] = data[index(i + 1)];
		}
		length--;
		return oldData;
	}
	void clear() {
		delete[] data;
		data = NULL;
		size = 0;
		begin = 0;
		length = 0;
	}
	bool empty() { return size; }
	void show() {
		for (int i = 0; i < length; i++) {
			cout << data[index(i)] << endl;
		}
	}
};

class Data
{
private:
	string nameSportsman;
	char sex;
	string dateofbirth;
	string section;
public:
	Data()
	{
		this->nameSportsman = "";
		this->sex = NULL;
		this->dateofbirth = "";
		this->section = "";
	}
	Data(string nameSportsman, char sex, string dateofbirth, string section)
	{
		this->nameSportsman = nameSportsman;
		this->sex = sex;
		this->dateofbirth = dateofbirth;
		this->section = section;
	}
	Data& operator=(Data& arg)
	{
		if (this == &arg) {
			return *this;
		}
		this->nameSportsman = arg.nameSportsman;
		this->sex = arg.sex;
		this->dateofbirth = arg.dateofbirth;
		this->section = arg.section;
		return *this;
	}
	friend ostream& operator<<(ostream&, const Data&);
};
ostream& operator<<(ostream& out, const Data& arg)
{
	out.width(24);
	out << left << arg.nameSportsman;
	out.width(8);
	out << left << arg.sex;
	out.width(24);
	out << left << arg.dateofbirth;
	out.width(12);
	out << left << arg.section;
	return out;
}

int main()
{
	setlocale(0, "");
	const int n = 6;
	Data tab[n] = {
		Data("Иванов Алексей", 'М', "2009-10-30", "Волейбол"),
		Data("Сидорова Наталья", 'Ж', "2008-02-27", "Волейбол"),
		Data("Сидорова Ольга", 'Ж', "2008-02-27", "Волейбол"),
		Data("Петров Артем", 'М', "2006-07-23", "Футбол"),
		Data("Цукерман Артур", 'М', "2005-04-21", "Футбол"),
		Data("Фролов Антон", 'М', "2008-12-31", "Бадминтон")
	};
	Vector<Data> obj;
	obj.pushBack(tab[4]);
	obj.pushBack(tab[5]);
	cout << "Добавление через pushBack две последние строки из таблицы: " << endl;
	for (int i = 0; i < n - 2; i++) {
		obj.insert(tab[i]);
	}
	cout << "Добавление через insert первые 4 строки из таблицы: " << endl;
	cout << "Выводим все таблицу: " << endl;
	obj.show();
	cout << "Удаляем два элемента из массива с помощью popBack" << endl;
	obj.popBack();
	obj.popBack();
	cout << "Удаляем элемент из середины с помощью erase" << endl;
	obj.erase(1);	
	cout << "Выводим все элементы: " << endl;
	obj.show();
	return 0;
}