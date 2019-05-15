#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
int i = 0, j = 0;
void menu()
{
	int flag = 1, i = 0, i_start = 0, i_end = 2, j = 0;
	char select;
	while (flag == 1)
	{
		system("cls");
		printf("\t\tKREST  A N D  NULL\n");
		printf("\t\t\tMenu: \n");
		output_menu(i);
		i = joy(i, i_start, i_end, &flag);
	}
	printf("%d %d\n", flag, i);
	if (i == 2)
		game();
}
int joy(int i, int start, int end, int *flag, int j)
{
	char select = getch();
	switch(select)
	{
		case 13:
		{
			*flag = 0;
		}
		case 119: // вверх
		{
			if (i == start) {
				i = end;
				//output_menu(i);
				system("cls");
				return i;
			} 
			if (i > start) {
				i--;
				//output_menu(i);
				system("cls");
				return i;
			}
		}
		case 115: // вниз
		{
			if (i == end) {
				i = start;
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
void game()
{
	int mass[3][3] = {0};
	int flag = 1, k = 0;
	while (flag == 1)
	{
		system("cls");
		printf("Play:\nVash hod:\n");
		move(mass);
		mass[i + 1][j] = 1;
		area_output(mass);
		i = (rand() % 3); j = (rand() % 3);
		while (((mass[i][j] == 1) && (mass[i][j] != 0)) && (mass[i][j] != 2))
		{
			i = (rand() % 3); j = (rand() % 3);
		}
		mass[i][j] = 2;
		area_output(mass);
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					if (mass[i][j] == 1)
						k++;
				}
				if (k == 3) {
					system("cls");
					area_output(mass);
					sleep(2);
					congrutalation(1);
				}
				k = 0;
			} 
			k = 0;
			for (int j = 0; j < 2; j++) {
				for (int i = 0; i < 2; i++) {
					if (mass[i][j] == 2)
						k++;
				}
				if (k == 3) {
					system("cls");
					area_output(mass);
					sleep(2);
					congrutalation(2);
				}
				k = 0;
			}
	}
}
void congrutalation(int tr)
{
	system("cls");
	if (tr == 1) printf("ROBIN BOBIN KOJANIE UBLUDOK WIN!\n");
	if (tr == 2) printf("YAVNO DYDYA ARTAMONOV I CHERTOVA MACHINA OBSTAVILI TEBYA.\nNO NE PEREJIVAYA, V SLEDUYACHIE RAZ POVEZET.\n");
	sleep(5);
	menu();
}
void move(int mass[][3])
{
	int flag = 1;
	char select;
	while (flag == 1)
	{
		system("cls");
		printf("Play:\nVash hod:\n");
		for (int p = 0; p < 3; p++) {
			for (int k = 0; k < 3; k++) {
				if ((i == p) && (k == j)) {
					printf("\t*");
				} else if (mass[p][k] == 0) {
					printf("\t+");
				} else if (mass[p][k] == 1) {
					printf("\tX");
				} else if (mass[p][k] == 2) {
					printf("\tO");
				}
			}
			printf("\n");
		}
		select = getch();
		switch(select)
		{
			case 13:
			{
				flag = 0;
			}
		case 119: // вверх
		{
			if (i == 0) {
				i = 2;
				//output_menu(i);
				system("cls");
			} else {
				i--;
				system("cls");
			}
		}
		case 115: // вниз
		{
			if (i == 2) {
				i = 0;
				//output_menu(i);
				system("cls");
			} else {
				i++;
				//output_menu(i);
				system("cls");
			}
		}
			case 100: // вправо
			{
				if (j == 2) {
					j = 0;
					system("cls");
				} else {
					j++;
					system("cls");
				}
			}
			case 97: // влево
			{
				if (j < 0) {
					j = 2;
					system("cls");
				} else {
					j--;
					system("cls");
				}
			}
		}
	}
}
void area_output(int mass[][3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (mass[i][j] == 0) {
				printf("\t+");
			} else if (mass[i][j] == 1) {
				printf("\tX");
			} else if (mass[i][j] == 2) {
				printf("\tO");
			}
		}
		printf("\n\n");
	}
}
int main()
{
	srand(time(NULL));
	menu();
	return 0;
}