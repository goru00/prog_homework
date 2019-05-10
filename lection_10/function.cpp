#include<iostream>
using namespace std;
int f(int a)
{
	return ++a;
}
int main()
{long long int z = 1;
	cout << f(z) << endl;
	return 0;
}