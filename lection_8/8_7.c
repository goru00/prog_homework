// Трехмерный массив
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void input();
void output();
int main()
{
	srand(time(NULL));
	int ***array, n, m, t;
	printf("Введите размерность трехмерного массива: (все 3 измерения)"); scanf("%d %d %d", &n, &m, &t);
	array = (int ***)malloc(n * sizeof(int));
	input(array, n, m, t);
	free(array);
	return 0;
}
void output(int ***mass, int size_n, int size_m, int size_k)
{
	for (int i = 0; i < size_n; i++)
	{
		for (int j = 0; j < size_m; j++)
		{
			for (int k = 0; k < size_k; k++)
			{
				printf("%3d", mass[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
void input(int ***mass, int size_n, int size_m, int size_k)
{
	for (int i = 0; i < size_n; i++)
	{
		mass[i] = (int **)malloc(size_m * sizeof(int));
		for (int j = 0; j < size_m; j++)
		{
			mass[i][j] = (int *)malloc(size_k * sizeof(int));
			for (int k = 0; k < size_k; k++)
			{
				mass[i][j][k] = (rand() % 10);
			}
		}
	}
	output(mass, size_n, size_m, size_k);
}