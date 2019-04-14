#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "windows.h"
#define SIZE_N 12
#define SIZE_M 12
void maze();
void output();
void menu();
void output_menu();
void end_game(int);
int move(int **);
struct records
{
	int *point;
};
struct food
{
	int x;
	int y;
	int eat_food;
};
struct hero
{
	int **s;
	int snake_x;
	int snake_y;
	int density;
	int mooving;
};
int main()
{
	struct records pointer;
	pointer.point = NULL;
	srand(time(NULL));
	FILE *file = fopen("records.txt", "w+");
	int **snake = NULL;
	snake = (int **)malloc(SIZE_N * sizeof(int));
	menu(file, snake);
	return 0;
}
void menu(FILE *file, int **snake)
{
	struct food apple;
	int flag = 1;
	int i = 0;
	char text;
	while(flag == 1)
	{
		printf("Z M E Y K A\n");
		printf("Peredvigatsya s pomochiu W(vverh) i S(vniz): \n");
		printf("Menu: \n");
		output_menu(i);
		text = getch();
		switch(text)
		{
			case 32:
			{
				int point = i;
				if (point == 0){
					maze(snake);
					break;
				}
				if (point == 1)
					Records(file);
				if (point == 2)
					flag = 0;
			}
			case 119:
			{
				if (i == 0) {
					i = 2;
					output_menu(i);
					system("cls");
				} 
				if (i > 0) {
					i--;
					output_menu(i);
					system("cls");
				}
			}
			case 115:
			{
				if (i == 2) {
					i = 0;
					output_menu(i);
					system("cls");
				} else {
					i++;
					output_menu(i);
					system("cls");
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
void Records(FILE *file)
{
	while(!feof(file))
	{

	}
}
void maze(int **snake)
{
	struct food apple;
	struct hero h;
	apple.x = (rand() % 10) + 1;
	apple.y = (rand() % 10) + 1;
	int flag = 1;
	while (flag == 1)
	{
		for (int i = 0; i < SIZE_N; i++)
		{
			snake[i] = (int *)malloc(SIZE_M * sizeof(int));
			for (int j = 0; j < SIZE_M; j++)
				snake[i][j] = 9;
		}
		for (int i = 1; i < SIZE_N - 1; i++)
		{
			for (int j = 1; j < SIZE_M - 1; j++)
			{
				snake[i][j] = 0;
			}
		}
		snake[apple.x][apple.y] = 5;
		output(snake);
		flag = move(snake);
	}
}
int move(int **snake)
{
	struct hero h;
	int score = 0;
	h.density = 1;
	h.mooving = 0;
	h.snake_x = (rand() % 10) + 1;
	h.snake_y = (rand() % 10) + 1;
	char nap;
	int flag = 1;
	while(flag == 1)
	{
		while(!kbhit())
		{
			if (h.mooving == 0) { // move down
				for (int i = h.snake_x; i < SIZE_N - 1; i++) 
				{
					if (i > h.snake_x)
						snake[i - 1][h.snake_y] = 0;
					snake[i][h.snake_y] = 1;
					h.snake_x++;
					output(snake);
					if (i + 1 == SIZE_N - 1){
						end_game(score);
						flag = 0;
						break;
					}
				}
			}
			if (h.mooving == 1) { // move left
				for (int j = h.snake_y; j > 0; j--) 
				{
					if (j < h.snake_y)
						snake[h.snake_x][j - 1] = 0;
					snake[h.snake_x][j] = 1;
					output(snake);
					if (j - 1 == 0){
						end_game(score);
						flag = 0;
						break;
					}
				}
			}
			if (h.mooving == 2) { // move right
				for (int i = h.snake_x; i < SIZE_N - 1; i++) 
				{
					if (i > h.snake_x)
						snake[i - 1][h.snake_y] = 0;
					snake[i][h.snake_y] = 1;
					output(snake);
					if (i + 1 == SIZE_N - 1){
						end_game(score);
						flag = 0;
						break;
					}
				}
			}
			if (h.mooving == 3) {
				for (int i = h.snake_x; i < SIZE_N - 1; i++) 
				{
					if (i > h.snake_x)
						snake[i - 1][h.snake_y] = 0;
					snake[i][h.snake_y] = 1;
					output(snake);
					if (i + 1 == SIZE_N - 1){
						end_game(score);
						flag = 0;
						break;
					}
				}
			}
		}nap = getch();
	}
}
void end_game(int score)
{
	system("cls");
	struct food apple;
	apple.eat_food = score;
	printf("End GAME !\nFinal Score: %d\n", apple.eat_food);
	sleep(1);
}
void output(int **snake)
{
	struct food apple;
	printf("Score: %d\n", apple.eat_food);
	printf("Peremechenie na W i D\n");
	for (int i = 0; i < SIZE_N; i++)
	{
		for (int j = 0; j < SIZE_M; j++)
		{
			printf("%d", snake[i][j]);
		}
		printf("\n");
	}
	sleep(1);
	system("cls");
}
