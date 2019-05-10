#include<iostream> // библа для работы с потоками ввода/вывода
using namespace std; // сокращение для операторов cout, cin, endl.
int main()
{
	int a;
	cout <<"Введите целое число: "; // cout - оператор вывода.
	cin >> a; // cin - оператор ввода.
	cout << "Итак, Вы ввели число " << a << endl; // endl - аналогия \n.
	return 0;
}