#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#define SIZE_N 7
#define SIZE_M 7
int i = 0, j = 0, area[7][7] = {0}, i_start = 0, i_end = 2, i_menu = 0, N, i_question, ration = 0, left_ration, k, p;
void menu();
void game(char *);
void output(int focus[][4], int);
int marker(int focus[][4], int, char *);
void congratulation();
void question();
int joy(int *flag, int focus[][4], int N, char *start_time);
int joy_menu(int *);
void Records();
void output_menu();
void logo();
char * settime(struct tm *u)
{
  char s[40];
  char *tmp;
  for (int i = 0; i<40; i++) s[i] = 0;
  int length = strftime(s, 40, "%d.%m.%Y %H:%M:%S", u);
  tmp = (char*)malloc(sizeof(s));
  strcpy(tmp, s);
  return(tmp);
}
void menu()
{
	struct tm *u;
	char *start_time; char *finish_time;
	ration = 0;
	int flag = 1;
	i = 0, j = 0;
	i_menu = 0;
	i_end = 2;
	const time_t timer = time(NULL);
	u = localtime(&timer);
	start_time = settime(u);
	while (flag == 1)
	{
		logo();
		output_menu(i_menu);
		joy_menu(&flag);
	}
	if (i_menu == 0) 
		game(start_time);
	if (i_menu == 1){
		Records(0, start_time, finish_time);
	}
	if (i_menu == 2)
		exit(1);
}
void game(char *start_time)
{
	N = (rand() % 4) + 2; int focus[N][4];
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
	k = (rand() % N); p = (rand() % 4); 
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
		joy(&flag, focus, N, start_time);
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
		printf("Подсказка. Нажмите [ENTER], чтобы воспользоваться ею.\n");
	} else if ((i == 3) && (j == 0)) {
		printf("Войти в комнату на Западе.Нажмите [ENTER] чтобы войти в комнату\n");
	} else if ((i == 0) && (j == 3)) {
		printf("Войти в комнату на Севере.Нажмите [ENTER] чтобы войти в комнату\n");
	} else if ((i == 3) && (j == 6)) {
		printf("Войти в комнату на Востоке.Нажмите [ENTER] чтобы войти в комнату\n");
	} else if ((i == 6) && (j == 3)) {
		printf("Войти в комнату на Юге.Нажмите [ENTER] чтобы войти в комнату\n");
	}
	printf("Стороны света: \n");
	printf("    С    \n"
		   "З---|---В\n"
		   "    Ю    \n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%2d", focus[i][j]);
		}
		printf("\n");
	}
}
int marker(int focus[][4], int N, char *start_time)
{
	if ((i == 3) && (j == 3)) {
		int flag = 1; char text[100];
		i_question = (rand() % N); 
		printf("За правильный ответ Вы получите подсказку\nВнимание, вопрос: ");
		question();
		printf("Ваш ответ: "); scanf("%s", text);
	} else if ((i == k) && (p == j)) {
		congratulation(start_time);
	} else if ((i == 3) && (j == 0)) {
		if ((focus[ration][0] == focus[ration - 1][2]) && ((ration > 0) && (focus[ration][0] != 5)) && ((focus[ration][0] != 0) && (focus[ration - 1][2] != 0))) {
			left_ration = ration;
			ration--;
		} else if ((focus[ration][0] == focus[ration + 1][2]) && ((ration >= 0) && (focus[ration][0] != 0)) && (focus[ration + 1][2] != 0)) {
			left_ration = ration;
			ration++;
		} else if (focus[ration][0] == 5) {
			congratulation(start_time);
		} else if (focus[ration][0] == 0) {
			printf("Дверь закрыта!\n");
			sleep(1);
			return 1;
		}
	} else if ((i == 0) && (j == 3)) {
		if ((focus[ration][1] == focus[ration - 1][3]) && ((ration > 0) && (focus[ration][1] != 5)) && ((focus[ration][1] != 0) && (focus[ration - 1][3] != 0))) {
			left_ration = ration;
			ration--;
		} else if ((focus[ration][1] == focus[ration + 1][3]) && ((ration >= 0)) && (focus[ration][1] != 0) && (focus[ration + 1][3] != 0)) {
			left_ration = ration;
			ration++;
		} else if (focus[ration][1] == 5) {
			congratulation(start_time);
		} else if (focus[ration][1] == 0) {
			printf("Дверь закрыта!\n");
			sleep(1);
			return 1;
		}
	} else if ((i == 3) && (j == 6)) {
		if ((focus[ration][2] == focus[ration - 1][0]) && ((ration > 0) && (focus[ration][2] != 5)) && ((focus[ration][2] != 0) && (focus[ration - 1][0] != 0))) {
			left_ration = ration;
			ration--;
		} else if ((focus[ration][2] == focus[ration + 1][0]) && ((ration >= 0)) && ((focus[ration][2] != 0) && (focus[ration + 1][0] != 0))) {
			left_ration = ration;
			ration++;
		} else if (focus[ration][2] == 5) {
			congratulation(start_time);
		} else if (focus[ration][2] == 0) {
			printf("Дверь закрыта!\n");
			sleep(1);
			return 1;
		}
	} else if ((i == 6) && (j == 3)) {
		if ((focus[ration][3] == focus[ration - 1][1]) && ((ration > 0) && (focus[ration][3] != 5)) && ((focus[ration][3] != 0) && (focus[ration - 1][1] != 0))) {
			left_ration = ration;
			ration--;
		} else if ((focus[ration][3] == focus[ration + 1][1]) && (ration >= 0) && ((focus[ration][3] != 0) && (focus[ration + 1][1] != 0))) {
			left_ration = ration;
			ration++;
		} else if (focus[ration][3] == 5) {
			congratulation(start_time);
		} else if (focus[ration][3] == 0) {
			printf("Дверь закрыта!\n");
			sleep(1);
			return 1;
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
		if ((k == 1) && (ration != N))
			focus[ration][i_rand] = 1;
		if ((i_rand == 0) && ((k == 1)) && (ration != N)) {
			focus[ration + 1][2] = 1; 
		} else if ((i_rand == 1) && ((k == 1)) && (ration != N)) {
			focus[ration + 1][3] = 1;
		} else if ((i_rand == 2) && ((k == 1)) && (ration != N)) {
			focus[ration + 1][0] = 1;
		} else if ((i_rand == 3) && ((k == 1)) && (ration != N)) {
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
void congratulation(char *start_time)
{
	char *finish_time;
	struct tm *u;
	const time_t timer = time(NULL);
	u = localtime(&timer);
	system("cls");
	printf("Поздравляем! Вы нашли выход!\n");
	finish_time = settime(u);
	printf("Время начала: "); puts(start_time);
	printf("\nКонец: "); puts(finish_time);
	Records(1, start_time, finish_time);
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
int joy(int *flag, int focus[][4], int N, char *start_time)
{
	char select = getch();
	switch(select)
	{
		case 13:
		{
			system("cls");
			marker(focus, N, start_time);
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
void Records(int N, char *start_time, char *finish_time)
{
	char text;
	if (N == 1) {
		FILE *records = fopen("data.txt", "a+");
		fprintf(records, "%s %s\n", start_time, finish_time);
		fclose(records);
	} else if (N == 0) {
		do
		{
			system("cls");
			printf("Результаты: \n\n");
			FILE *records = fopen("data.txt", "r+");
			char mass[100];
			while(fgets(mass, 100, records))
			{
				if (mass[strlen(mass) - 1] == '\n') {
					mass[strlen(mass) - 1] = '\0';
			}
				printf("%s\n", mass);
			}
		} while (getch() != 27);
		menu();
	}
}
void output_menu(int kursor)
{
	if (kursor == 0) 
		printf("\t\t[*] - Новая игра\n\t\t - Лучшие результаты\n\t\t - Выход из игры\n");
	if (kursor == 1) 
		printf("\t\t - Новая игра\n\t\t[*] - Лучшие результаты\n\t\t - Выход из игры\n");
	if (kursor == 2) 
		printf("\t\t - Новая игра\n\t\t - Лучшие результаты\n\t\t[*] - Выход из игры\n");
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
	printf("\t\tМеню: \n");
}
int main()
{
	system("chcp 866");
	srand(time(NULL));
	menu();
	return 0;
}