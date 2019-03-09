#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void output();
void input();
void relocate();
void pop();
void push();
void asc();
void desc();
int main()
{
	int *array = NULL, n, d;
	printf("Введите размерность массива: "); scanf("%d", &n);
	array = (int *)malloc(n * sizeof(int));
	input(array, n);
	output(array, n);
	int (*a[2])(int *, int) = {push, pop};
	printf("Выберете действие: (1 - добавить. 2 - взять) "); scanf("%d", &d);
  relocate((*a[d - 1])(array, n), d);
  free(array);
	return 0;
}
void output(int *mass, int count)
{
	for (int i = 0; i < count; i++)
		printf("a[%d] = %d\n", i, mass[i]);
}
void input(int *mass, int count)
{
	for (int i = 0; i < count; i++)
		mass[i] = i + 1;
}
void asc(int *mass, int count)
{
 	int i = 0, buf, swap = 0;
  	while (i < count)
  	{
    	if (i + 1 != count && mass[i] < mass[i + 1])  
    	{
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
}
void desc(int *mass, int count)
{
 	int i = 0, buf, swap = 0;
  	while (i < count)
  	{
    	if (i + 1 != count && mass[i] > mass[i + 1])  
    	{
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