#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include <windows.h>
#define SIZE_N 10
#define SIZE_M 10
int enemy_ships_one[4][2], enemy_ships_two[3][2], enemy_ships_three[2][2], enemy_ships_four[1][2];
int alien_ships_one[4][2], alien_ships_two[3][2], alien_ships_three[2][2], alien_ships_four[1][2];
int area_alien[SIZE_N][SIZE_M], area_enemy[SIZE_N][SIZE_M];
int i = 0, j = 0, i_start = 0, i_end = 2, i_menu = 0;
void menu()
{
	int flag = 1;
	i = 0, j = 0;
	i_menu = 0;
	while (flag == 1)
	{
		logo();
		output_menu(i_menu);
		joy_menu(&flag);
	}
	if (i_menu == 0) 
		game();
	if (i_menu == 2)
		exit(1);
}
void output()
{
	printf("\tAlien area\n");
	for (int i = 0; i < SIZE_N; i++) {
		for (int j = 0; j < SIZE_M; j++) {
			printf("%2d", area_alien[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\tEnemy area\n");
	for (int i = 0; i < SIZE_N; i++) {
		for (int j = 0; j < SIZE_M; j++) {
			printf("%2d", area_enemy[i][j]);
		}
		printf("\n");
	}
	printf("Dlya vihoda najmite ESC\n\n\n");
}
void game()
{
	int flag = 1;
	while (flag == 1)
	{
		output();
		joy(&flag);
		output();
	}
	menu();
}
void logo()
{
	system("cls");
	printf("\t\t\tW A R S H I P S\n");
	printf("\t\tMenu: \n");
}
int joy_menu(int *flag)
{
	char select = getch();
	switch(select)
	{
		case 13:
		{
			system("cls");
			*flag = 0;
			return i_menu;
		}
		case 56: // вверх
		{
			if (i_menu == i_start) {
				i_menu = i_end;
				//output_menu(i);
				system("cls");
				return i_menu;
			} 
			if (i_menu > i_start) {
				i_menu--;
				//output_menu(i);
				system("cls");
				return i_menu;
			}
		}
		case 50: // вниз
		{
			if (i_menu == i_end) {
				i_menu = i_start;
				//output_menu(i);
				system("cls");
				return i_menu;
			} else {
				i_menu++;
				//output_menu(i);
				system("cls");
				return i_menu;
			}
		}
		default: 
		{
			system("cls");
		}
	}
}
int joy(int *flag)
{
	char select = getch();
	switch(select)
	{
		case 13:
		{
			system("cls");
			//marker();
			return i;
		}
		case 27:
		{
			*flag = 0;
		}
		case 56: // вверх
		{
			if (i == i_start) {
				i = i_end;
				//output_menu(i);
				system("cls");
				return i;
			} 
			if (i > i_start) {
				i--;
				//output_menu(i);
				system("cls");
				return i;
			}
		}
		case 50: // вниз
		{
			if (i == i_end) {
				i = i_start;
				//output_menu(i);
				system("cls");
				return i;
			} else {
				i++;
				//output_menu(i);
				system("cls");
				return i;
			}
		}
		case 54: // вправо
			{
				if (j == i_end) {
					j = i_start;
					system("cls");
				} else {
					j++;
					system("cls");
				}
				j++;
			}
		case 52: // влево
		{
			if (j <= i_start) {
				j = i_end;
				system("cls");
			} else {
				j--;
				system("cls");
			}
		}
		default: 
		{
			system("cls");
		}
	}
}
void output_menu(int kursor)
{
	if (kursor == 0) 
		printf("\t\t[*] - New Game\n\t\t - Records\n\t\t - Exit\n");
	if (kursor == 1) 
		printf("\t\t - New Game\n\t\t[*] - Records\n\t\t - Exit\n");
	if (kursor == 2) 
		printf("\t\t - New Game\n\t\t - Records\n\t\t[*] - Exit\n");
}
int main()
{
	for (int i = 0; i < SIZE_N; i++) {
		for (int j = 0; j < SIZE_M; j++) {
			area_alien[i][j] = 0;
			area_enemy[i][j] = 0;
		}
	}
	srand(time(NULL));
	menu();
	return 0;
}