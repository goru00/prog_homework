#include <iostream>
using namespace std;
class personal
{
protected:
    int price, tab_N;
    string name, dolgnost;
public:
    personal(int tab_N, string name, string dolgnost, int price)
    {
        this->tab_N = tab_N;
        this->price = price;
        this->name = name;
        this->dolgnost = dolgnost;
    }
    personal(int tab_N)
    {
        this->tab_N = tab_N;
    }
    void show() { cout << "Табельный №:\tФИО работника:\tДолжность:\tОклад(руб)\n" << tab_N << "\t\t" << name << "\t" << dolgnost << "\t" << price << endl; }
    };
class group : public personal
{
protected:
    string N_group, name_group;
public:
    group(string N_group, string name_group, personal p) : personal(p)
    {
        this->N_group = N_group;
        this->name_group = name_group;
    }
    string num_group()
    {
        return N_group;
    }
    void show() { cout << "№ группы:\tНазвание группы:\tТабельный № воспитателя:\n" << N_group << "\t\t" << name_group << "\t\t\t" << personal::tab_N << endl; }
    };
class children
{
protected:
    int N_index;
    string name, date;
    group *name_group;
public:
    children(int N_index, string name, string date, group *n_group)
    {
        this->N_index = N_index;
        this->name = name;
        this->date = date;
        this->name_group = n_group;
    }
    void show() { cout << "№ порядковый:\tФИО ребенка:\tДата рождения:\t№ группы\n" << N_index << "\t\t" << name << "\t" << date << "\t" << name_group->num_group() << endl; }
    };
int main()
{
    setlocale(0, "");
    personal Samohina(108, "Самохина В.П", "Ст.воспитатель", 32000);
    personal Firsova(110, "Фирсова М.В", "Воспитатель", 27000);
    personal Frolova(102, "Фролова Н.Г", "Воспитатель", 27000);
    personal Samohvalova(107, "Самохвалова И.В", "Воспитатель", 27000);
    personal Furmanov(120, "Фурманова Н.И", "Зав.детским садиком", 52000);
    group Little("М", "Младшая", Samohina);
    group Middle("С", "Средняя", Samohvalova);
    group Prepare("П", "Подготовительная", Samohina);
    group big_little("Я", "Ясельная", Firsova);
    children Ivanov(1001, "Иванов Алеша", "2009-10-30", &Middle);
    children Sidorova(1002, "Сидорова Наташа", "2008-02-27", &Middle);
    children Petrova(1006, "Петрова Катя", "2009-09-17", &Middle);
    children Petrov(1003, "Петров Артем", "2006-07-23", &Little);
    children Frolov(1004, "Фролов Антон", "2008-12-31", &Little);
    children Fedorova(1005, "Федорова Ирина", "2009-09-12", &Prepare);
    cout << "Персонал: " << endl;
    Samohina.show();
    Firsova.show();
    Frolova.show();
    Samohvalova.show();
    Furmanov.show();
    cout << "\n" << "Группы: " << endl;
    Little.show();
    Middle.show();
    Prepare.show();
    big_little.show();
    cout << "\n" << "Дети: " << endl;
    Ivanov.show();
    Sidorova.show();
    Petrova.show();
    Petrov.show();
    Frolov.show();
    Fedorova.show();
    return 0;
}
