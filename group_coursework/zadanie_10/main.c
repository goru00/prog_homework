#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#ifdef _WIN32
	#include<conio.h>
	#include <windows.h>
#endif
char button();
void game();
void output();
void ur();
void test_area();
void logo();
int menu();
void display();
void output_menu();
int joy_menu(int *);
int joy(int *);
int i = 0, j = 0, i_start = 0, i_end = 2, i_menu = 0;
int area[3][3] = {0};
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
char button()
{
    char select;
    #if _WIN32
        select = getch();
        printf("WIN\n");
    #else
        system("stty raw");
        select = getchar();
        system("stty cooked");
        printf("UNIX\n");
    #endif
    return select;
}
void display()
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
void output()
{
	display();
	for (int k = 0; k < i_end + 1; k++) {
		for (int p = 0; p < i_end + 1; p++)
		{
			if ((i == k) && (p == j)) {
				printf("\t*");
			} else if (area[k][p] == 0) {
				printf("\t+");
			} else if (area[k][p] == 1) {
				printf("\tX");
			} else if (area[k][p] == 2) {
				printf("\tO");
			}
		}
		printf("\n");
	}
	printf("Для выхода в главное меню нажмите [ESCAPE]\n\n\n");
}
void ur(int k_h, int k_comp)
{
	if (k_h == 3) {
		display();
		printf("Победа игрока!\n");
		sleep(5);
		menu();
	} else if (k_comp == 3) {
		display();
		printf("Победа компьютера\n");
		sleep(5);
		menu();
	}
}
void test_area()
{
	int k = 0;
	int count_h = 0, count_comp = 0;
	int i_count = 0, j_count;
	while (i_count < 3)
	{
		for (j_count = 0; j_count < i_end + 1; j_count++) {
			if (area[i_count][j_count] == 1) {
				count_h++;
			} else if (area[i_count][j_count] == 2) {
				count_comp++;
			}
		}
		ur(count_h, count_comp);
		count_h = 0; count_comp = 0;
		i_count++;
	}
	j_count = 0;
	while (j_count < 3)
	{
		for (int i_count = 0; i_count < i_end + 1; i_count++) {
			if (area[i_count][j_count] == 1) {
				count_h++;
			} else if (area[i_count][j_count] == 2) {
				count_comp++;
			}
		}
		ur(count_h, count_comp);
		count_h = 0; count_comp = 0;
		j_count++;
	}
	if (((area[0][0] == 1) && (area[1][1] == 1)) && (area[2][2] == 1)) {
		count_h = 3; count_comp = 0;
		ur(count_h, count_comp);
	} else if (((area[0][2] == 1) && (area[1][1] == 1)) && (area[2][0] == 1)) {
		count_h = 3; count_comp = 0;
		ur(count_h, count_comp);
	}
	if (((area[0][0] == 2) && (area[1][1] == 2)) && (area[2][2] == 2)) {
		count_h = 0; count_comp = 3;
		ur(count_h, count_comp);
	} else if (((area[0][2] == 2) && (area[1][1] == 2)) && (area[2][0] == 2)) {
		count_h = 0; count_comp = 3;
		ur(count_h, count_comp);
	}
	for (int i = 0; i < i_end + 1; i++) {
		for (int j = 0; j < i_end + 1; j++) {
			if (area[i][j] != 0)
				k++;
		}
	}
	if (k == 9) {
		printf("К сожалению, ничья.\n");
		sleep(2);
		menu();
	}
}
void logo()
{
	display();
	printf("\t\t\tКрестики-Нолики\n");
	printf("\t\tМеню: \n");
}
int menu()
{
	int flag = 1;
	i = 0, j = 0;
	i_menu = 0;
	for (int i = 0; i < i_end + 1; i++) {
		for (int j = 0; j < i_end + 1; j++) {
			area[i][j] = 0;
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
void output_menu(int kursor)
{
	if (kursor == 0) 
		printf("\t\t[*] - Новая игра\n\t\t - Результаты\n\t\t - Выход\n");
	if (kursor == 1) 
		printf("\t\t - Новая игра\n\t\t[*] - Результаты\n\t\t - Выход\n");
	if (kursor == 2) 
		printf("\t\t - Новая игра\n\t\t - Результаты\n\t\t[*] - Выход\n");
}
void marker()
{
	if (area[i][j] == 0) {
		area[i][j] = 1;
	} else {
		display();
		printf("Клетка занята!\n");
		sleep(2);
		game();
	} 
	test_area();
	int flag = 1, i_comp, j_comp;
	while (flag == 1)
	{
		i_comp = (rand() % 3); j_comp = (rand() % 3);
		if (area[i_comp][j_comp] == 0) {
			area[i_comp][j_comp] = 2;
			flag = 0;
		}
	}
	display();
	test_area();
}
int joy_menu(int *flag)
{
	char select;
	select = button();
	switch(select)
	{
		case 13:
		{
			display();
			*flag = 0;
			return i_menu;
		}
		case 56: // вверх
		{
			if (i_menu == i_start) {
				i_menu = i_end;
				//output_menu(i);
				display();
				return i_menu;
			} 
			if (i_menu > i_start) {
				i_menu--;
				//output_menu(i);
				display();
				return i_menu;
			}
		}
		case 50: // вниз
		{
			if (i_menu == i_end) {
				i_menu = i_start;
				//output_menu(i);
				display();
				return i_menu;
			} else {
				i_menu++;
				//output_menu(i);
				display();
				return i_menu;
			}
		}
		default: 
		{
			display();
		}
	}
}
int joy(int *flag)
{
	char select;
	select = button();
	switch(select)
	{
		case 13:
		{
			display();
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
				i = i_end;
				//output_menu(i);
				display();
				return i;
			} 
			if (i > i_start) {
				i--;
				//output_menu(i);
				display();
				return i;
			}
		}
		case 50: // вниз
		{
			if (i == i_end) {
				i = i_start;
				//output_menu(i);
				display();
				return i;
			} else {
				i++;
				//output_menu(i);
				display();
				return i;
			}
		}
		case 54: // вправо
			{
				if (j == i_end) {
					j = i_start;
					display();
				} else {
					j++;
					display();
				}
				j++;
			}
		case 52: // влево
		{
			if (j <= i_start) {
				j = i_end;
				display();
			} else {
				j--;
				display();
			}
		}
		default: 
		{
			display();
		}
	}
}
int main()
{
	#ifdef _WIN32
		system("chcp 866");
	#endif
	srand(time(NULL));
	menu();
	return 0;
}