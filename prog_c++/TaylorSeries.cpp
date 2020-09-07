#include<iostream>
#include<string>
#include<cmath>
using namespace std;
double f(double x, double eps)
{
	double sum = 0, a = 1;
	int n = 1;
	while (abs(a) >= eps)
	{
		sum += a;
		a *= x / n;
		n++;
	}
	return sum;
}
int main()
{
	double x, eps;
	cin >> x;
	cin >> eps;
	cout << f(x, eps) << "\t" << exp(x) << endl;
	return 0;
}