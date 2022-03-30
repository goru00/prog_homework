#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
class Data
{
private:
    int tabNum;
    string fio;
    string direction;
    int price;
public:
    Data() : tabNum(0), fio(""), direction(""), price(0) { }
    Data(int tabNum, string fio, string direction, int price)
    {
        this->tabNum = tabNum;
        this->fio = fio;
        this->direction = direction;
        this->price = price;
    }
    friend bool operator<(const Data& arg1, const Data& arg2)
    {
        return arg1.direction < arg2.direction || (arg1.direction == arg2.direction && arg1.fio < arg2.fio);
    }
    friend ostream& operator<<(ostream& out, const Data& arg)
    {
        out << arg.tabNum << " " << arg.fio << " " << arg.direction << " " << arg.price << endl;
        return out;
    }
};
int main()
{
    setlocale(0, "");
    const int n = 3;
    vector<Data> obj1(n), obj2(n);
    obj1 = {
      Data(2345, "Иванов Сергей Степанович", "Разнорабочий", 28000),
      Data(2346, "Краснов Сергей Георгиевич", "Сантехник", 32000),
      Data(2347, "Бендер Остап Ибрагимович", "Директор", 62000)
    };
    obj2 = {
      Data(2349, "Петров Сергей Степанович", "Электрик", 36000),
      Data(2356, "Кирпичев Владимир Викторович", "Начальник смены", 48000),
      Data(2378, "Абрамов Иван Петрович", "Электрик", 36000)
    };
    cout << "Список 1:" << endl;
    copy(obj1.begin(), obj1.end(), ostream_iterator<Data>(cout));
    cout << endl;
    cout << "Список 2:" << endl;
    copy(obj2.begin(), obj2.end(), ostream_iterator<Data>(cout));
    vector<Data> obj3(n);
    obj3 = obj1;
    copy(obj2.begin(), obj2.end(), back_inserter(obj3));
    cout << endl;
    cout << "Список 3:" << endl;
    copy(obj3.begin(), obj3.end(), ostream_iterator<Data>(cout));
    cout << endl << "Отсортируем список 3: " << endl;
    sort(obj3.begin(), obj3.end());
    copy(obj3.begin(), obj3.end(), ostream_iterator<Data>(cout));
    return 0;
}
