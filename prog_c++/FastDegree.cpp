#include<iostream>
#include<string>
using namespace std;
int f(int x, int n)
{
	int res = 1;
	while (n)
	{
		if (n == 0) return 1;
		if (n != 0 && n % 2 == 0) res *= x/2 * x;
		if (n != 0 && n % 2 != 0) res *= x;
		--n;
	}
	return res;
}
int main()
{
	int x;
	int n;
	cin >> x;
	cin >> n;
	cout << f(x, n);
	return 0;
}
