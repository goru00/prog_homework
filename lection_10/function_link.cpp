#include<iostream>
using namespace std;
void f(int &);
void f(int & a)
{
	a++;
}
int main()
{
	int a;
	cin >> a;
	f(a);
	cout << a << endl;
}