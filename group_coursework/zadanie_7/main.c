#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include <windows.h>
int i = 0, j = 0, i_start = 0, i_end = 2, i_menu = 0;
int area[4][4], numb[15];
int menu()
{
	int flag = 1;
	i = 0, j = 0;
	i_menu = 0;
	for (int i = 0; i < 16; i++) numb[i] = i;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			area[i][j] = 16;
		}
	}
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
void game()
{
	int flag = 1;
	input();
	i = 0, j = 0;
	while (flag == 1)
	{
		system("cls");
		output();
		joy(&flag);
		output();
	}
	menu();
}
void input()
{
	int i_rand = (rand() % 4), j_rand = (rand() % 4);
	area[i_rand][j_rand] = numb[0];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (area[i][j] == 16) {
				while (numb[i_rand] == 0) {
					i_rand = (rand() % 16); 
				}
				area[i][j] = numb[i_rand];
				numb[i_rand] = 0;
			}
		}
	}
}
void output()
{
	for (int k = 0; k < 4; k++) {
		for (int p = 0; p < 4; p++) {
			if ((i == k) && (p == j)) {
				printf("\t*");
			} else if (area[k][p] >= 0)  {
				printf("\t%d", area[k][p]);
			}
		}
		printf("\n");
	}
}
void logo()
{
	system("cls");
	printf("\t\t\tP Y T N A S H K I\n");
	printf("\t\tMenu: \n");
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
void marker()
{
	int flag_marker;
	if (area[i][j] == 0) {
		printf("NELZYA!\n");
		sleep(2);
		game();
	} else if (area[i][j] > 0) {
		if (area[i + 1][j] == 0) {
			area[i + 1][j] = area[i][j];
			area[i + 1][j] = 0;
			game();
		} else if (area[i - 1][j] == 0) {
			area[i - 1][j] = area[i][j];
			area[i - 1][j] = 0;
			game();
		} else if (area[i][j + 1] == 0) {
			area[i][j + 1] = area[i][j];
			area[i][j + 1] = 0;
			game();
		} else if (area[i][j - 1] == 0) {
			area[i][j - 1] = area[i][j];
			area[i][j - 1] = 0;
			game();
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
			marker();
			return i;
		}
		case 27:
		{
			*flag = 0;
		}
		case 56: // вверх
		{
			if (i == i_start) {
				i = i_end + 1;
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
			if (i == i_end + 1) {
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
				if (j == i_end + 1) {
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
				j = i_end + 1;
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
int main()
{
	srand(time(NULL));
	menu();
	return 0;
}