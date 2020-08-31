#include <iostream>
#include <string>
using namespace std;
template <typename T>
void gnomeSort(T mass[], int count)
{
    int i = 0;
    T temp;
    while (i < count)
    {
        if (i == 0 || mass[i - 1] <= mass[i]) {
            i++;
        }
        else {
            temp = mass[i];
            mass[i] = mass[i - 1];
            --i;
            mass[i] = temp;
        }
    }
}
class contract
{
private:
    string num_contract;
    string org;
    string street;
    int price;
public:
    contract() : num_contract(""), org(""), street(""), price(0) { }
    contract(string num_contract, string org, string street, int price)
    {
        this->num_contract = num_contract;
        this->org = org;
        this->street = street;
        this->price = price;
    }
    int operator<=(contract& arg1)
    {
        return (price < arg1.price) || (price == arg1.price) && (org < arg1.org);
    }
    friend ostream& operator<<(ostream&, contract&);
};
ostream& operator<<(ostream& out, contract& arg1)
{
    out.width(10); out << left << arg1.num_contract;
    out.width(24); out << left << arg1.org;
    out.width(44); out << left << arg1.street;
    out.width(12); out << arg1.price << endl;
    return out;
}
int main()
{
    setlocale(0, "");
    const int n = 6;
    contract A[n] = {
        contract("2018-01", "ООО «Топаз»", "г.Котельники, 2-ой проезд, д.23", 200000),
        contract("2018-03", "ООО «Вариант»", "г.Дзержинский, Матросова -14", 3000000),
        contract("2019-05", "ОАО «Вымпел»", "г.Москва, Таганская -23", 3500000),
        contract("2019-07", "ООО «Рога и копыта» ", "г.Одесса, ул.Малая Арнаутская, д.12", 350000),
        contract("2020-01", "ОАО «Спартак»", "г.Москва, Кривоколенный пер. -14 стр.3", 1200000),
        contract("2020-02", "ООО «Гламур»", "г.Москва, ул. Марксистская, д.25, оф.37", 3000000)
    };
    gnomeSort(A, n);
    for (int i = 0; i < n; i++)
    {
        cout << A[i];
    }
    return 0;
}