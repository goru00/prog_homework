#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int **array;
	int n, m;
	srand(time(NULL));
	printf("Введите размерность массива: "); scanf("%d %d", &n, &m);
	array = (int **)malloc(n * sizeof(int));
	input(n, m, array);
	if (size_m > size_n)
		array = (int **)realloc(array, ++n * sizeof(int));
	if (size_n > )
	trans(n, m, array);
	return 0;
}
void trans(int size_n, int size_m, int **mass)
{
	if (size_m > size_n){
		mass[i] = (int *)realloc(mass, ++size_m * sizeof(int));
		for (int i = 0; i <= size_n; i++)
		{
			for (int j = size_m, k = 0; j <= size_m + 1; j++, k++)
			{
				mass[0][j] = mass[size_n - k][k];
			}
		}
	}
}
void input(int size_n, int size_m, int **mass)
{
	for (int i = 0; i < size_n; i++)
	{
		array = (int *)malloc(size_m * sizeof(int));
		for (int j = 0; j < size_m; j++)
		{
			mass[i][j] = (rand() % 10);
		}
	}
}	
