#include<stdio.h>
#include<stdlib.h>
#define VALUE 9
int main()
{
	int a[VALUE];
	for (int i = 0; i <= VALUE; i++)
	{
		a[i] = (rand() % 100) + 1;
	}
	int k = a[1], x;
	a[1] = a[0];
	for (int i = 2; i <= VALUE; i++)
	{
		x = a[i];
		a[i] = k;
		//a[i + 1] = k;
		printf("\na[%d] = %d\n", i + 1, a[i + 1]);
	}
	return 0;
}