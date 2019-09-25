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
    personal get_personal[] = {
        personal(108, "Самохина В.П", "Ст.воспитатель", 32000),
        personal(110, "Фирсова М.В", "Воспитатель", 27000),
        personal(102, "Фролова Н.Г", "Воспитатель", 27000),
        personal(107, "Самохвалова И.В", "Воспитатель", 27000),
        personal(120, "Фурманова Н.И", "Зав.детским садиком", 52000)
    };
    group get_group[] = {
        group("М", "Младшая", get_personal[0]),
        group("С", "Средняя", get_personal[3]),
        group("П", "Подготовительная", get_personal[0]),
        group("Я", "Ясельная", get_personal[1])
    };
    children get_childer[] = {
        children(1001, "Иванов Алеша", "2009-10-30", &get_group[1]),
        children(1002, "Сидорова Наташа", "2008-02-27", &get_group[1]),
        children(1006, "Петрова Катя", "2009-09-17", &get_group[1]),
        children(1003, "Петров Артем", "2006-07-23", &get_group[0]),
        children(1004, "Фролов Антон", "2008-12-31", &get_group[0]),
        children(1005, "Федорова Ирина", "2009-09-12", &get_group[2])
    };
    cout << "Персонал: " << endl;
    for (int i = 0; i < 5; i++) get_personal[i].show();
    cout << "\n" << "Группы: " << endl;
    for (int i = 0; i < 4; i++) get_group[i].show();
    cout << "\n" << "Дети: " << endl;
    for (int i = 0; i < 6; i++) get_childer[i].show();
    return 0;
}
