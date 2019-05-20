#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include <windows.h>
int i = 0, j = 0, i_start = 0, i_end = 2, i_menu = 0;
int area[3][3] = {0};
void game()
{
	int flag = 1, hum;
	while (flag == 1)
	{
		output();
		joy(&flag);
		output();
	}
	menu();
}
void output()
{
	system("cls");
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
	printf("Dlya vihoda najmite ESC\n\n\n");
}
void ur(int k_h, int k_comp)
{
	if (k_h == 3) {
		system("cls");
		printf("POBEDA KOJANOGO UBLUDKA!\n");
		sleep(5);
		menu();
	} else if (k_comp == 3) {
		system("cls");
		printf("HAHAHA, PAREN, ETO  I K E A!\nTI PROIGRAL!\n");
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
		printf("NICHYA, POCONI\nDAVAITE PO NOVOY\n");
		sleep(2);
		menu();
	}
}
void logo()
{
	system("cls");
	printf("\t\t\tKREST  A N D  NULL\n");
	printf("\t\tMenu: \n");
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
		printf("\t\t[*] - New Game\n\t\t - Records\n\t\t - Exit\n");
	if (kursor == 1) 
		printf("\t\t - New Game\n\t\t[*] - Records\n\t\t - Exit\n");
	if (kursor == 2) 
		printf("\t\t - New Game\n\t\t - Records\n\t\t[*] - Exit\n");
}
void marker()
{
	if (area[i][j] == 0) {
		area[i][j] = 1;
	} else {
		system("cls");
		printf("NELZYA!\n");
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
	system("cls");
	test_area();
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
int main()
{
	srand(time(NULL));
	menu();
	return 0;
}