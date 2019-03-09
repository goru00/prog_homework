#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void input();
void output();
void pop();
void push();
void relocate();
int main()
{
	int *array = NULL, n, d;
	printf("Введите кол-во книг в стопке: "); scanf("%d", &n);
	array = (int *)malloc(n * sizeof(int));
	input(array, n);
	output(array, n);
	int (*a[2])(int *, int) = {push, pop};
	printf("Выберете действие: (1 - добавить. 2 - взять) "); scanf("%d", &d);
	relocate((*a[d - 1])(array, n), d);
	if (d == 2)
		output(array, n - 1);
	if (d == 1){
		array[n] = n + 1;
		output(array, n + 1);
	}
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
void push(int *mass, int count)
{
	mass = (int *)realloc(mass, (count + 1) * sizeof(int));
}
void pop(int *mass, int count)
{
	mass = (int *)realloc(mass, (count - 1) * sizeof(int));
}