#include <iostream>
#include <string>
using namespace std;

template <typename T>
void selectionSort(T mass[], int size)
{
    int min;
    T temp;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (mass[j] > mass[min])
            {
                min = j;
            }
        }
        temp = mass[i];
        mass[i] = mass[min];
        mass[min] = temp;
    }
}

class personal
{
private:
    int number;
    string name_personal;
    string qual;
    int salary;
public:
    personal() : number(0), name_personal(""), qual(""), salary(0) {}
    personal(int number, string name_personal, string qual, int salary)
    {
        this->number = number;
        this->name_personal = name_personal;
        this->qual = qual;
        this->salary = salary;
    }
    int operator>(personal& arg2) { return (salary > arg2.salary) || (salary == arg2.salary) && (name_personal < arg2.name_personal); }
    friend ostream& operator<<(ostream&, personal& pers);
};

ostream& operator<<(ostream& out, personal& pers)
{
    out.width(8); out << left << pers.number;
    out.width(20); out << left << pers.name_personal;
    out.width(25); out << left << pers.qual;
    out.width(12); out << pers.salary << endl;
    return out;
}

int main()
{
    setlocale(0, "");
    const int n = 6;
    personal tab[n] = {
        personal(108, "Фамохина В.П", "Ст. воспитатель", 32000),
        personal(110, "Фирсова М.В", "Воспитатель", 27000),
        personal(102, "Фролова Н.Г", "Воспитатель", 27000),
        personal(107, "Самохвалова И.В", "Воспитатель", 27000),
        personal(108, "Бендер О.И", "Зав.хозяйством", 45000),
        personal(120, "Фурманов Н.И", "Зав. детским садиком", 52000)
    };
    selectionSort(tab, n);
    for (int i = 0; i < n; i++)
    {
        cout << tab[i];
    }
    return 0;
}