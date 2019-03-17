#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void err();
void output();
void input();
void sort();
int minelem(int *, int);
int main()
{
	int *array = NULL, n;
	printf("Введите длину массива: "); scanf("%d", &n);
	array = (int *)malloc(n * sizeof(int));
	input(array, n);
	printf("Все числа: \n");
	output(array, n);
	err(array, n);
	output(array, n);
	sort(array, n);
	output(array, n);
	n = minelem(array, n);
	output(array, n);
	free(array);
	return 0;
}
int minelem(int *mass, int count)
{
	int k = 0;
	for (int i = 0; i < count; i++)
	{
		if (mass[i] > 0)
			k++;
	}
	mass = (int *)realloc(mass, k * sizeof(int));
	printf("Итоговый вариант: \n\n");
	return k;
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
	printf("Отсортированный массив: \n\n");
}
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
	printf("После фильтрованием эратосфеном: \n\n");
}
void output(int *mass, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("a[%d] = %d\n", i, mass[i]);
	}
}
void input(int *mass, int count)
{
	for (int i = 0; i < count; i++)
	{
		mass[i] = i + 1;
	}
}