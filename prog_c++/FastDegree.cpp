#include<iostream>
#include<string>
using namespace std;
int f(int x, int n)
{
	int res = 1;
	if (n == 0)
	{
		return 1;
	}
	else {
		while (n)
		{
			res *= x;
			--n;
		}
	}
	return res;
}
int main()
{
	int x, n;
	cin >> x;
	cin >> n;
	cout << f(x, n);
	return 0;
}
