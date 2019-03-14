#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void input();
void output();
int main()
{
	srand(time(NULL));
	int **array, *mrow, n;
	printf("Введите кол-во строк в массиве: "); scanf("%d", &n);
	array = (int **)malloc(n * sizeof(int));
	mrow = (int *)malloc(n * sizeof(int));
	input(array, mrow, n);
	free(array);
	free(mrow);
	return 0;
}
void output(int **mass, int *mrow, int size_n)
{
	printf("\n");
	for (int i = 0; i < size_n; i++)
	{
		for (int j = 0; j < mrow[i]; j++)
		{
			printf("%3d", mass[i][j]);
		}
		printf("\n");
	}
}
void input(int **mass, int *mrow, int size_n)
{
	for (int i = 0; i < size_n; i++)
	{
		printf("Введите кол-во столбцовв строке: "); scanf("%d", &mrow[i]);
		mass[i] = (int *)malloc(mrow[i] * sizeof(int));
		for (int j = 0; j < mrow[i]; j++)
			mass[i][j] = (rand() % 10);
	}
	output(mass, mrow, size_n);
}