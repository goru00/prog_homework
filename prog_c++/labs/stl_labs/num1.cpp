#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
class Data
{
private:
    string num_doc;
    string name;
    string street;
    int price;
public:
    Data() : num_doc(""), name(""), street(""), price(0) { }
    Data(string num_doc, string name, string street, int price)
    {
        this->num_doc = num_doc;
        this->name = name;
        this->street = street;
        this->price = price;
    }
    friend bool operator<(const Data& arg1, const Data& arg2)
    {
        return arg1.price < arg2.price || (arg1.price == arg2.price && arg1.name < arg2.name);
    }
    friend ostream& operator<<(ostream& out, const Data& arg)
    {
        out << arg.num_doc << " " << arg.name << " " << arg.street << " " << arg.price << endl;
        return out;
    }
};
int main()
{
    setlocale(0, "");
    const int n = 3;
    vector<Data> obj1(n), obj2(n);
    obj1 = {
      Data("2018-01", "ООО «Топаз»", "г.Котельники, 2-ой проезд, д.23", 200000),
      Data("2018-03", "ООО «Вариант»", "г. Дзержинский, Матросова, д.14", 3000000),
      Data("2019-05", "ОАО «Вымпел»", "г. Москва, Таганская, д.23", 3500000)
    };
    obj2 = {
      Data("2019-07", "ООО «Рога и копыта»", "г. Одесса, ул. Малая Арнаутская, д.12", 350000),
      Data("2020-01", "ОАО «Спартак»", "г. Москва, Кривоколенный пер.14 стр. 3", 1200000),
      Data("2020-02", "ООО «Гламур»", "г. Москва, ул. Марксистская, д.25, оф. 37", 3000000)
    };
    cout << "Список 1:" << endl;
    copy(obj1.begin(), obj1.end(), ostream_iterator<Data>(cout, " "));
    cout << endl;
    cout << "Список 2:" << endl;
    copy(obj2.begin(), obj2.end(), ostream_iterator<Data>(cout, " "));
    vector<Data> obj3(n);
    obj3 = obj1;
    copy(obj2.begin(), obj2.end(), back_inserter(obj3));
    cout << endl;
    cout << "Список 3:" << endl;
    copy(obj3.begin(), obj3.end(), ostream_iterator<Data>(cout, " "));
    cout << endl << "Отсортируем список 3: " << endl;
    sort(obj3.begin(), obj3.end());
    copy(obj3.begin(), obj3.end(), ostream_iterator<Data>(cout, " "));
    return 0;
}