#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
int joy(int, int, int, int *);
void output_game();
void records_input();
void output_pool(int);
void game();
void output_menu(int);
void records_output();
void logo()
{
	system("cls");
	printf("\t\t\tJ O I N  C A S I N O\n");
	printf("\t\tMenu: \n");
}
void menu()
{
	int flag = 1, i = 0, i_start = 0, i_end = 2;
	char select;
	while (flag == 1)
	{
		logo();
		output_menu(i);
		i = joy(i, i_start, i_end, &flag);
	}
	printf("%d %d\n", flag, i);
	if (i == 2)
		game();
	if (i == 1)
		records_output();
}
int joy(int i, int start, int end, int *flag)
{
	char select = getch();
	switch(select)
	{
		case 13:
		{
			*flag = 0;
		}
		case 119:
		{
			if (i == start) {
				i = end;
				output_menu(i);
				system("cls");
				return i;
			} 
			if (i > start) {
				i--;
				output_menu(i);
				system("cls");
				return i;
			}
		}
		case 115:
		{
			if (i == end) {
				i = start;
				output_menu(i);
				system("cls");
				return i;
			} else {
				i++;
				output_menu(i);
				system("cls");
				return i;
			}
		}
	}
}
void game()
{
	int flag_game = 1;
	while (flag_game == 1)
	{
		int pool = 100, flag = 1, i = 0, i_end = 10, i_start = 0;
		char select;
		while (flag == 1)
		{
			system("cls");
			printf("You pool: %d\n", pool);
			printf("Select number 2 to 12: \n");
			output_game(i);
			i = joy(i, i_start, i_end, &flag);
		}
		int num;
		if (i == 10) num = 2;
		if (i == 0) num = 3;
		if (i == 1) num = 4;
		if (i == 2) num = 5;
		if (i == 3) num = 6;
		if (i == 4) num = 7;
		if (i == 5) num = 8;
		if (i == 6) num = 9;
		if (i == 7) num = 10;
		if (i == 8) num = 11;
		if (i == 9) num = 12;
		flag = 1, i_end = 4;
		i = 0;
		while (flag == 1)
		{
			printf("Sdelaite stavku: \n");
			output_pool(i);
			i = joy(i, i_start, i_end, &flag);
		}
		int bank = 0;
		if (i == 4) {
			bank += 10;
			pool -= 10;
		}
		if (i == 0) {
			if (pool >= 50) {
				bank += 50;
				pool -= 50;
			} else if (pool < 50) {
				system("cls");
				printf("Stavka ne mojet bit bolshe balansa\nBuy!\n");
				flag_game = 0;
			}
		}
		if (i == 1) {
			if (pool >= 100) {
				bank += 100;
				pool -= 100;
			} else if (pool < 100) {
				system("cls");
				printf("Stavka ne mojet bit bolshe balansa\nBuy!\n");
				flag_game = 0;
			}
		}
		if (i == 2) {
			if (pool >= 150) {
				bank += 150;
				pool -= 150;
			} else if (pool < 150) {
				system("cls");
				printf("Stavka ne mojet bit bolshe balansa\nBuy!\n");
				flag_game = 0;
			}
		}
		if (i == 3) {
			int pool_put;
			printf("Vvedite svoi pool: "); scanf("%d", &pool_put);
			if (pool >= pool_put) {
				bank += pool_put;
				pool -= pool_put;
			} else if (pool < pool_put) {
				system("cls");
				printf("Stavka ne mojet bit bolshe balansa\nBuy!\n");
				flag_game = 0;
			}
		}
		int one_rand = (rand() % 7) + 1;
		int sum_rand = 0; sum_rand += one_rand;
		one_rand = (rand() % 7) + 1; sum_rand += one_rand;
		printf("Summa vipavshih cifar ravna: %d\n", sum_rand);
		printf("Vi zagadali chislo: %d\n", num);
		if (sum_rand == num) {
			printf("EDRIT VI KOJIMA!\nVi poluchaete v 4 raza bolshe deneg za vigrash.\n");
			bank *= 4;
			pool += bank;
			bank = 0;
			printf("Na rukah: %d\n", pool);
		} else if (((sum_rand > 7) && (num > 7)) || ((sum_rand < 7) && (num < 7))) {
			printf("NEPLOHO MORYACHOK\nZabirai bablo.\n");
			pool += (bank * 2);
			bank = 0;
			printf("Na rukah: %d\n", pool);
			sleep(2);
		} else {
			printf("Kapec ti LOH.\nDAVAI DOSVIDANIYA.\n");
			records_input(pool);
			flag_game = 0;
			sleep(1);
		}
	}
}
void output_pool(int kursor)
{
	if (kursor == 0)
		printf("[*] - 10\n- 50\n- 100\n- 150\n- Drugoi pool\n");
	if (kursor == 1)
		printf("- 10\n[*] - 50\n- 100\n- 150\n- Drugoi pool\n");
	if (kursor == 2)
		printf("- 10\n- 50\n[*] - 100\n- 150\n- Drugoi pool\n");
	if (kursor == 3)
		printf("- 10\n- 50\n- 100\n[*] - 150\n- Drugoi pool\n");
	if (kursor == 4)
		printf("- 10\n- 50\n- 100\n- 150\n[*]- Drugoi pool\n");
}
void records_input(int pool)
{
	time_t lt;
	int It = time(NULL);
	FILE *records = fopen("records.txt", "a+");
	fprintf(records, "%d\n", pool);
	fclose(records);
}
void records_output()
{
	printf("DAVAI, SCHITAI SVOI KOPEIKI: \n");
}
void output_game(int kursor)
{
	if (kursor == 0)
		printf("[*] - 2\n- 3\n- 4\n- 5\n- 6\n- 7\n- 8\n- 9\n- 10\n- 11\n- 12\n");
	if (kursor == 1)
		printf("- 2\n[*] - 3\n- 4\n- 5\n- 6\n- 7\n- 8\n- 9\n- 10\n- 11\n- 12\n");
	if (kursor == 2)
		printf("- 2\n- 3\n[*] - 4\n- 5\n- 6\n- 7\n- 8\n- 9\n- 10\n- 11\n- 12\n");
	if (kursor == 3)
		printf("- 2\n- 3\n- 4\n[*] - 5\n- 6\n- 7\n- 8\n- 9\n- 10\n- 11\n- 12\n");
	if (kursor == 4)
		printf("- 2\n- 3\n- 4\n- 5\n[*] - 6\n- 7\n- 8\n- 9\n- 10\n- 11\n- 12\n");
	if (kursor == 5)
		printf("- 2\n- 3\n- 4\n- 5\n- 6\n[*] - 7\n- 8\n- 9\n- 10\n- 11\n- 12\n");
	if (kursor == 6)
		printf("- 2\n- 3\n- 4\n- 5\n- 6\n- 7\n[*] - 8\n- 9\n- 10\n- 11\n- 12\n");
	if (kursor == 7)
		printf("- 2\n- 3\n- 4\n- 5\n- 6\n- 7\n- 8\n[*] - 9\n- 10\n- 11\n- 12\n");
	if (kursor == 8)
		printf("- 2\n- 3\n- 4\n- 5\n- 6\n- 7\n- 8\n- 9\n[*] - 10\n- 11\n- 12\n");
	if (kursor == 9)
		printf("- 2\n- 3\n- 4\n- 5\n- 6\n- 7\n- 8\n- 9\n- 10\n[*] - 11\n- 12\n");
	if (kursor == 10)
		printf("- 2\n- 3\n- 4\n- 5\n- 6\n- 7\n- 8\n- 9\n- 10\n- 11\n[*]- 12\n");
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
	srand(time(NULL));
	menu();
	return 0;
}
