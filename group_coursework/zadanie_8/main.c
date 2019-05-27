#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#define SIZE_N 7
#define SIZE_M 7
int i = 0, j = 0, area[7][7] = {0}, i_start = 0, i_end = 2, i_menu = 0, N, i_question, ration = 0, left_ration;
void menu()
{
	ration = 0;
	int flag = 1;
	i = 0, j = 0;
	i_menu = 0;
	i_end = 2;
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
	N = (rand() % 4) + 2; int focus[N][4], rooms = 0;
	area[3][0] = 2; area[0][3] = 2; area[3][6] = 2; area[6][3] = 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			focus[i][j] = 0;
		}
	}
	int i_rand;
	for (int i = 0; i < 4; i++) {
		if (focus[ration][i] != 5) {
			i_rand = (rand() % 4);
			focus[ration][i_rand] = 1;
			break;
		}
	}
	if (i_rand == 0) {
		focus[ration + 1][2] = 1;
	} else if (i_rand == 1) {
		focus[ration + 1][3] = 1;
	} else if (i_rand == 2) {
		focus[ration + 1][0] = 1;
	} else if (i_rand == 3) {
		focus[ration + 1][1] = 1;
	}
	int k = (rand() % N), p = (rand() % 4); 
	while (focus[k][p] != 0)
	{
		k = (rand() % N), p = (rand() % 4);
	}
	focus[k][p] = 5;
	for (int j = 1; j < 6; j++) area[3][j] = 1;
	for (int i = 1; i < 6; i++) area[i][3] = 1;
	area[3][3] = 5;
	int flag = 1;
	i = 3; j = 1; i_end = 6;
	while (flag == 1)
	{
		output(focus, N);
		joy(&flag, focus, N);
		output(focus, N);
	}
	menu();
}
void output(int focus[][4], int N)
{
	system("cls");
	for (int k = 0; k < SIZE_N; k++) {
		for (int p = 0; p < SIZE_M; p++) {
			if ((i == k) && (j == p)) {
				if ((j == 3) && (i != 3)) {
					printf("\t*");
				} else printf(" * ");
			} else if (area[k][p] == 2) {
				if ((k == 3) && (p == 0)) {
					printf("X");
				} else if ((k == 3) && (p == 6)) {
					printf("X");
				} else printf("\tX");
			} else if (area[k][p] == 0) {
				printf(" ");
			} else if (area[k][p] == 1) {
				if (p == 3) {
					printf("\t|");
				} else printf(" - ");
			} else if (area[k][p] == 5) {
				printf(" ? ");
			} 
		}
		printf("\n");
	}
	if ((i == 3) && (j == 3)) {
		printf("Podskazka. Najmite [ENTER] chtobi vospolzovatsya eu.\n");
	} else if ((i == 3) && (j == 0)) {
		printf("Voiti v komnatu na Zapade.Najmite [ENTER] chtobi voiti v komnatu\n");
	} else if ((i == 0) && (j == 3)) {
		printf("Voiti v komnatu na Severe.Najmite [ENTER] chtobi voiti v komnatu\n");
	} else if ((i == 3) && (j == 6)) {
		printf("Voiti v komnatu na Vostoke.Najmite [ENTER] chtobi voiti v komnatu\n");
	} else if ((i == 6) && (j == 3)) {
		printf("Voiti v komnatu na Yge.Najmite [ENTER] chtobi voiti v komnatu\n");
	}
	printf("Napravleniya: \n");
	printf("    C    \n"
		   "3---|---V\n"
		   "    Y    \n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%2d", focus[i][j]);
		}
		printf("\n");
	}
}
void marker(int focus[][4], int N)
{
	if ((i == 3) && (j == 3)) {
		int flag = 1; char text[100];
		i_question = (rand() % N); 
		printf("Za pravilnyi otvet vi poluchite podksazku.\nVnimanie, vopros: ");
		question();
		printf("Vash otvet: "); scanf("%s", text);
	}
	if ((i == 3) && (j == 0)) {
		if ((focus[ration][0] == focus[ration - 1][2]) && (ration > 0)) {
			left_ration = ration;
			ration--;
		} else if ((focus[ration][0] == focus[ration + 1][2]) && (ration >= 0)) {
			left_ration = ration;
			ration++;
		}
	} else if ((i == 0) && (j == 3)) {
		if ((focus[ration][1] == focus[ration - 1][3]) && (ration > 0)) {
			left_ration = ration;
			ration--;
		} else if ((focus[ration][1] == focus[ration + 1][3]) && (ration >= 0)) {
			left_ration = ration;
			ration++;
		}
	} else if ((i == 3) && (j == 6)) {
		if ((focus[ration][2] == focus[ration - 1][0]) && (ration > 0)) {
			left_ration = ration;
			ration--;
		} else if ((focus[ration][2] == focus[ration + 1][0]) && (ration >= 0)) {
			left_ration = ration;
			ration++;
		}
	} else if ((i == 6) && (j == 3)) {
		if ((focus[ration][3] == focus[ration - 1][1]) && (ration > 0)) {
			left_ration = ration;
			ration--;
		} else if ((focus[ration][3] == focus[ration + 1][1]) && (ration >= 0)) {
			left_ration = ration;
			ration++;
		}
	} 
	int i_rand = rand() % 4, k = 0;
	if ((ration >= 1) && ((ration < N) && (left_ration < ration))) {
		while ((focus[ration][i_rand] == 1) || (focus[ration][i_rand] == 5)) {
			i_rand = rand() % 4;
		}
		for (int j = 0; j < 4; j++) {
			if (focus[ration][j] == 1) k++;
		}
		if (k == 1)
			focus[ration][i_rand] = 1;
		if (i_rand == 0) {
			focus[ration + 1][2] = 1; 
		} else if (i_rand == 1) {
			focus[ration + 1][3] = 1;
		} else if (i_rand == 2) {
			focus[ration + 1][0] = 1;
		} else if (i_rand == 3) {
			focus[ration + 1][1] = 1;
		}
	}
	if ((i == 3) && (j == 0)) { 
		j = 6;
	} else if ((i == 3) && (j == 6)) { 
		j = 0;
	} else if ((i == 6) && (j == 3)) { 
		i = 0;	
	} else if ((i == 0) && (j == 3)) { 
		i = 6;
	}
}
void congratulation()
{
	system("cls");
	printf("Congratulation! Vi nashli vihod.\n");
	sleep(2);
	menu();
}
void question()
{
	int i = 0;
	char mass[100];
	FILE *file = fopen("question.txt", "r+");
	while(fgets(mass, 100, file))
	{
		if (mass[strlen(mass) - 1] == '\n') {
			mass[strlen(mass) - 1] = '\0';
		}
		if (i_question == i) {
			printf("%s\n", mass);
			break;
		}
		i++;
	}
	fclose(file);
}
int joy(int *flag, int focus[][4], int N)
{
	char select = getch();
	switch(select)
	{
		case 13:
		{
			system("cls");
			marker(focus, N);
			return i;
		}
		case 27:
		{
			*flag = 0;
		}
		case 56: // вверх
		{
			if (j == 3) {
				i--;
			}
			return i;
		}
		case 50: // вниз
		{
			if (j == 3) {
				i++;
			}
			return i;
		}
		case 54: // вправо
		{
			if (i == 3) {
				j++;
			}
			return j;
		}	
		case 52: // влево
		{
			if (i == 3) {
				j--;
			}
			return j;
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
void logo()
{
	system("cls");
	printf("\t\t\tL A B I R I N T\n");
	printf("\t\tMenu: \n");
}
int main()
{
	srand(time(NULL));
	menu();
	return 0;
}