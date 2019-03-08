#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void pluselem();
void sort();
void output();
void input();
int main()
{
	srand(time(NULL));
	int *array = NULL, n, m = 0, start = 0;
	printf("Введите длину массива: "); scanf("%d", &n);
	array = (int *)malloc(n * sizeof(int));
	input(array, n, start, m);
	printf("Исходный массив: \n\n");
	output(array, n, m);
	printf("Отсортированный массив: \n\n");
	sort(array, n, m);
	output(array, n, m);
	printf("\n\nНа сколько Вы хотите расширить массив: "); scanf("%d", &m);
	start = n;
	pluselem(array, n, m);
	input(array, n, start, m);
	sort(array, n, m);
	output(array, n, m);
	return 0;
}
void pluselem(int *mass, int count, int plus)
{
	mass = (int *)realloc(mass, (count + plus) * sizeof(int));
}
void sort(int *mass, int count, int plus)
{
	int buf, i = 0, swap = 0;
	while (i < (count + plus))
	{
		if (i + 1 != (count + plus) && mass[i] < mass[i + 1]){
			buf = mass[i];
			mass[i] = mass[i + 1];
			mass[i + 1] = buf;
			swap = 1;
		}
		i++;
		if (i == (count + plus) && swap == 1)
		{
			swap = 0;
			i = 0;
		}
	}
}
void output(int *mass, int count, int plus)
{
	for (int i = 0; i < (count + plus); i++)
		printf("a[%d] = %d\n", i, mass[i]);
}
void input(int *mass, int count, int start, int plus)
{
	for (int i = start; i < (count + plus); i++)
		mass[i] = (rand() % 50);
}