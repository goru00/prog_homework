#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define SIZE_N 12
#define SIZE_M 12
void maze();
void output();
void menu();
void output_menu();
struct records
{
	int *point;
};
int main()
{
	struct records pointer;
	pointer.point = NULL;
	
	FILE *file = fopen("records.txt", "w+");
	int **snake = NULL;
	snake = (int **)malloc(SIZE_N * sizeof(int));
	menu();
	return 0;
}
void menu()
{
	int i = 0;
	char text;
	while(1)
	{
		printf("Z M E Y K A\n");
		printf("Peredvigatsya s pomochiu W(vverh) i S(vniz): \n");
		printf("Menu: \n");
		output_menu(i);
		text = getch();
		switch(text)
		{
			case 119:
			{
				if (i == 0) {
					i = 2;
					output_menu(i);
				} 
				if (i > 0) {
					i--;
					output_menu(i);
				}
			}
			case 115:
			{
				if (i == 2) {
					i = 0;
					output_menu(i);
				} else {
					i++;
					output_menu(i);
				}
			}
		}
	}
}
void output_menu(int kursor)
{
	if (kursor == 0) 
		printf("[*] - New Game\n - Records\n - Exit\n");
	if (kursor == 1)
		printf(" - New Game\n[*] - Records\n - Exit\n");
	if (kursor == 2)
		printf(" - New Game\n - Records\n[*] - Exit\n");
}
void Records()
{

}
void maze(int **snake)
{
	for (int i = 0; i < SIZE_N; i++)
	{
		snake[i] = (int *)malloc(SIZE_M * sizeof(int));
		for (int j = 0; j < SIZE_M; j++)
			snake[i][j] = 9;
	}
	for (int i = 1; i < SIZE_N - 1; i++)
		for (int j = 1; j < SIZE_M - 1; j++)
				snake[i][j] = 0;
	output(snake);
}
void output(int **snake)
{
	for (int i = 0; i < SIZE_N; i++)
	{
		for (int j = 0; j < SIZE_M; j++)
		{
			printf("%d", snake[i][j]);
		}
		printf("\n");
	}
}
