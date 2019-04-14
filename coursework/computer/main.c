#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include "windows.h"
void menu();
void output_menu();
void create_command();
void list_command();
void input_command();
int main()
{
	int *ram = NULL; // оперативная память
	int *code_list = NULL; // массив команд
	ram = (int *)malloc(100 * sizeof(int)); // оперативная память
	FILE *battary = fopen("result.txt", "w+"); // аккумулятор
	FILE *command = fopen("command_list.txt", "a+"); // храним команды
	create_command(command);
	menu(ram, battary, command, code_list);
	return 0;
}
void menu(int *ram, FILE *battary, FILE *command, int *code_list)
{
	char select;
	int flag = 1, i = 0;
	while (flag == 1)
	{
		//system("cls");
		printf("\t\tOperation System K O J A N I E  M U D A K\n");
		printf("\t\t\t\tWelcome!\n");
		printf("\t\tMenu: \n\n");
		output_menu(i);
		select = getch();
		switch(select)
		{
			case 32:
			{
				int point = i;
				if (point == 3)
					flag = 0;
				if (point == 1)
					list_command(command, code_list);
				if (point == 3)
					input_command();
			}
			case 119:
			{
				if (i == 0) {
					i = 3;
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
				if (i == 3) {
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
void input_command()
{

}
void create_command(FILE *command)
{
	int code[] = {10, 11, 20, 21, 30, 31, 32, 40, 41, 42, 43};
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			fprintf(command, "%d%d\n", code[i], code[j]);
	fclose(command);
}
void list_command(FILE *command, int *code_list)
{
	code_list = (int *)malloc(121 * sizeof(int));
	command = fopen("command_list.txt", "r");
	printf("Najmite lubyu klavishu dlya podtverjdeniya\n");
	while (getch() != 8)
	{
		system("cls");
		for (int i = 0; i < 121; i++)
			fscanf(command, "%d", &code_list[i]);
		for (int i = 0; i < 121; i++)
			printf("[%d] . %d\n", i, code_list[i]);
		printf("Input <BACKSPACE> that is back.\n\n");
	}
	fclose(command);
}
void output_menu(int kursor)
{
	if (kursor == 0) 
		printf("\t\t[*] - Input Command\n\t\t - List Command\n\t\t - Run Command\n\t\t - Shutdown\n");
	if (kursor == 1) 
		printf("\t\t - Input Command\n\t\t[*] - List Command\n\t\t - Run Command\n\t\t - Shutdown\n");
	if (kursor == 2)
		printf("\t\t - Input Command\n\t\t - List Command\n\t\t[*] - Run Command\n\t\t - Shutdown\n");
	if (kursor == 3)
		printf("\t\t - Input Command\n\t\t - List Command\n\t\t - Run Command\n\t\t[*] - Shutdown\n");
}