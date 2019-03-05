#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE_N 12
#define SIZE_M 12
void buildmaze();
void output();
void startrunmaze();
void positionrunmaze();
int main()
{
	int maze[SIZE_N][SIZE_M];
	buildmaze((int*)maze);
	return 0;
}
void buildmaze(int mass[][SIZE_M])
{
	int count = 0;
	int strmaze;
	for (int i = 0; i < SIZE_N; i++)
	{
		printf("Посимвольно построим лабиринт: (только один символ!)"); 
		printf("\n");
		for (int j = 0; j < SIZE_M; j++)
		{
			scanf("%d", &strmaze); // 0 - проход; 1 - стена
			mass[i][j] = strmaze;
		}
		printf("\n\n");
		output((int*)mass, count);
		count++;
	}
	startrunmaze((int*)mass);
}
void startrunmaze(int maze[][SIZE_M])
{
	int *flag_start;
	int *flag_finish;
	positionrunmaze(flag_start, flag_finish, (int*)maze);
}
void positionrunmaze(int *fstart, int *ffinish, int maze[][SIZE_M])
{
	for (int i = 0; i < SIZE_N; i++)
	{
		for (int j = 0; j < SIZE_M; j++)
		{
			if (maze[0][j] == 0){
				fstart = &maze[i][j];
				break;
			}
			if (maze[i][0] == 0){
				fstart = &maze[i][j];
				break;
			}
			if (maze[SIZE_N - 1][j] == 0){
				fstart = &maze[i][j];
				break;
			}
			if (maze[SIZE_N - i - 1][SIZE_M - 1]){
				fstart = &maze[i][j];
				break;
			}
		}
	}
}
void output(int array[][SIZE_M], int count)
{
	for(int i = 0; i <= count; i++)
	{
		for(int j = 0; j < SIZE_M; j++)
		{
			printf("%d", array[i][j]);
		}
		printf("\n");
	}
}
