#include<iostream>
#include<string>
using namespace std;
int F(double *a, double *b, int n)
{
	double sum;
	for (int i = n - 1; i >= 0; i--)
	{
		sum = 0;
		for (int j = i + 1; j < n; j++)
		{
			sum += a[i * n + j] * b[j];
		}
		b[i] = (b[i] - sum) / a[i * n + i];
	}
	return 0;
}
int main()
{
	double a[] = { 2,3,4,5,0,6,7,8,0,0,9,10,0,0,0,11 };
	double b[] = { 40, 65, 67, 44 };
	const int n = 4;
	cout << F(a, b, n) << endl;
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << "\t";
	}
	cout << endl;
	return 0;
}
