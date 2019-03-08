#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void input();
void output();
void trans();
int main()
{
	srand(time(NULL));
	int **array, n, m;
	printf("Введите размерность массива(n и m): "); scanf("%d %d", &n, &m);
	array = (int **)malloc(n * sizeof(int));
	input(array, n, m);
	output(array, n, m);
	trans(array, n, m);
	output(array, n, m);
	return 0;
}
void trans(int **mass, int size_n, int size_m)
{
	int s;
	for (int i = 0; i < size_n; i++)
	{
		for (int j = i + 1; j < size_m; j++)
		{
			s = mass[i][j];
			mass[i][j] = mass[j][i];
			mass[j][i] = s;
		}
	}
}
void output(int **mass, int size_n, int size_m)
{
	for (int i = 0; i < size_n; i++)
	{
		for (int j = 0; j < size_m; j++)
		{
			printf("%3d", mass[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void input(int **mass, int size_n, int size_m)
{
	for (int i = 0; i < size_n; i++)
	{
		mass[i] = (int *)malloc(size_m * sizeof(int));
		for (int j = 0; j < size_m; j++)
		{
			mass[i][j] = (rand() % 50);
		}
	}
}