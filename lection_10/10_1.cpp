#include<iostream>
using namespace std;
void err(int *, int);
void output(int *, int);
void input(int *, int);
void err(int *mass, int count)
{
	int k = 0;
	for (int i = 0; i < count; i++)
	{
		k = 0;
		for (int j = 2; j <= 9; j++)
		{
			if ((mass[i] == 2) || (mass[i] == 3) || (mass[i] == 5) || (mass[i] == 7))
				break;
			if ((mass[i] % mass[i] == 0) && (mass[i] % j == 0))
				k++;
		}
		if (k >= 1)
			mass[i] = 0;
	}
}
void sort(int *mass, int count)
{
	int buf = 0, swap = 0, i = 0;
	while (i < count)
	{
		if (i + 1 != count && mass[i] < mass[i + 1]){
			buf = mass[i];
			mass[i] = mass[i + 1];
			mass[i + 1] = buf;
			swap = 1;
		}
		i++;
		if (i == count && swap == 1)
		{
			swap = 0;
			i = 0;
		}
	}
	cout << "Отсортированный массив: " << endl;
}
void input(int *mass, int count)
{
	for (int i = 0; i < count; i++)
	{
		mass[i] = i + 1;
	}
}
void output(int *mass, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (mass[i] != 0)
			cout << "a[" << i << "] = " << mass[i] << endl;
	}
}
int main()
{
	int n;
	cout << "Введите размерность массива: "; cin >> n;
	int *a = new int[n];
	input(a, n);
	output(a, n); 
	err(a, n);
	sort(a, n);
	output(a, n);
	delete [] a;
	return 0;
}