#include<iostream>
#include<string>
using namespace std;
class Quantity
{
public:
	Quantity()
	{
		size = 0;
		q = new int[size];
	}
	Quantity(int mass[], int size)
	{
		this->size = size;
		q = new int[size];
		for (int i = 0; i < size; i++)
		{
			q[i] = mass[i];
		}
	}
	Quantity(const Quantity& arg)
	{
		size = arg.size;
		q = new int[size];
		for (int i = 0; i < arg.size; i++)
		{
			q[i] = arg.q[i];
		}
	}
	Quantity Union(const Quantity& arg)
	{
		int count = size, index = 0;
		int* mass = new int[size + arg.size];
		for (int i = 0; i < size; i++) mass[i] = q[i];
		for (int i = 0; i < arg.size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (arg.q[i] == mass[j]) break;
				else index++;
			}
			if (size == index)
			{
				mass[count] = arg.q[i];
				count++;
			}
			index = 0;
		}
		Quantity C;
		C.size = count;
		C.q = new int[C.size];
		for (int i = 0; i < count; i++) C.q[i] = mass[i];
		return C;
	}
	Quantity Confluence(const Quantity& arg)
	{
		int count = 0;
		int* mass = new int[size];
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < arg.size; j++)
			{
				if (q[i] == arg.q[j])
				{
					mass[count] = arg.q[j];
					count++;
					break;
				}
			}
		}
		Quantity C;
		C.size = count;
		C.q = new int[C.size];
		for (int i = 0; i < count; i++) C.q[i] = mass[i];
		return C;
	}
	Quantity Difference(const Quantity& arg)
	{
		int count = 0, index = 0;
		int* mass = new int[size];
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < arg.size; j++)
			{
				if (q[i] == arg.q[j]) break;
				count++;
			}
			if (count == arg.size)
			{
				mass[index] = q[i];
				index++;
			}
			count = 0;
		}
		Quantity C;
		C.size = index;
		C.q = new int[index];
		for (int i = 0; i < index; i++) C.q[i] = mass[i];
		return C;
	}
	bool operator==(const Quantity& arg)
	{
		int count = 0;
		for (int i = 0; i < size; i++)
		{
			if (arg.q[i] == q[i]) count++;
		}
		return (count == size) ? true : false;
	}
	friend ostream& operator<<(ostream&, const Quantity&);
	static void Add(Quantity& arg, int a)
	{
		if (arg.size == 0) arg.q[0] = a;
		int* mass = new int[arg.size + 1];
		for (int i = 0; i < arg.size; i++) mass[i] = arg.q[i];
		mass[arg.size] = a;
		arg.size++;
		arg.q = new int[arg.size];
		for (int i = 0; i < arg.size; i++) arg.q[i] = mass[i];
		delete[] mass;
	}
private:
	int size;
	int* q;
};
ostream& operator<<(ostream& out, const Quantity& arg)
{
	for (int i = 0; i < arg.size; i++)
	{
		out.width(4);
		out << arg.q[i];
	}
	return out;
}
int main()
{
	setlocale(0, "");
	int n = 12;
	int qU[] = { 1,5,-3,7,9,12,56,-67,18,2,8,-4 }; // элементы для унив.множества U
	Quantity U; // универсальное множество (пусть будет U)
	for (int i = 0; i < n; i++)
	{
		Quantity::Add(U, qU[i]); // передаем в статический метод 
	}
	cout << "Унив.множество U:" << U << endl;
	int qA[] = { 1,5,-3,7 };
	Quantity A(qA, 4); // подмножество А. создаем для него элементы, передав массив qA в конструктор
	cout << "Подмножество А: " << A << endl;
	if (A == U) cout << "Подмножество А принадлежит унив.множеству U" << endl; // проверка принадлежности
	else cout << "Подмножество А не принадлежит унив.множеству U" << endl;
	int qB[] = { 1,7,8,-4,-3 };
	Quantity B(qB, 5);
	cout << "Подмножество B: " << B << endl;
	cout << "Пересечение множеств A и B:" << A.Confluence(B) << endl; // пересечение множеств
	cout << "Объединение множеств A и B:" << A.Union(B) << endl; // объединение множеств
	cout << "Разность подмножеств A\B: " << A.Difference(B) << endl; // разность множеств
	return 0;
}