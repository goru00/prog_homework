#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void input();
void output();
int pop(int *, int);
int push(int *, int);
void relocate();
int main()
{
	int *array = NULL, n, d;
	int (*a[2])(int *, int) = {push, pop};
	printf("Введите кол-во книг в стопке: "); scanf("%d", &n);
	array = (int *)malloc(n * sizeof(int));
	input(array, n);
	output(array, n);
	printf("Выберете действие: (1 - взять. 2 - добавить) "); scanf("%d", &d);
	n = relocate((*a[d - 1])(array, n), d);
	output(array, n - 1);
	free(array);
	return 0;
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
		printf("%d\n", mass[i]);
	}
}
void relocate(int *mass, int count)
{
	if (count == 1) {
		printf("Выбрано действие 'Добавить' \n");
	} else printf("Выбрано действие 'Взять' \n");
}
int push(int *mass, int count)
{
	mass = (int *)realloc(mass, (count + 1) * sizeof(int));
	mass[count] = count;
	return count + 1;
}
int pop(int *mass, int count)
{
	mass = (int *)realloc(mass, (count - 1) * sizeof(int));
	return count - 1;
}