#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<time.h>
void menu();
void output_menu();
void dict();
void shell_command();
void create_command();
void list_command();
void input_command();
void run_command();
void run_shell();
int main()
{
	int *ram = NULL; // оперативная память
	int *code_list = NULL; // массив команд
	ram = (int *)malloc(100 * sizeof(int)); // оперативная память
	FILE *battary = fopen("result.txt", "w+"); // аккумулятор
	FILE *command = fopen("command_list.txt", "w+"); // храним команды
	create_command(command);
	menu(ram, battary, command, code_list);
	return 0;
}
void logo()
{
	system("cls");
	printf("\t\tOperation System K O J I M A  G E N I U S\n");
}
void input_command()
{
	logo();
	//printf("Vvedite nomer komandi: "); scanf();
}
void menu(int *ram, FILE *battary, FILE *command, int *code_list)
{
	char select;
	int flag = 1, i = 0;
	while (flag == 1)
	{
		logo();
		printf("\t\t\t\tWelcome!\n");
		printf("\t\tMenu: \n\n");
		output_menu(i);
		select = getch();
		switch(select)
		{
			case 13:
			{
				if (i == 1) {
					list_command(command, code_list);
				}
				if (i == 4) {
					flag = 0;
					break;
				}
				if (i == 3) {
					run_shell(command, code_list, battary);
				}
				if (i == 2) {
					run_command(command, code_list);
				}
				if (i == 0) {
					input_command();
				}
			}
			case 119:
			{
				if (i == 0) {
					i = 4;
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
				if (i == 4) {
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
void run_shell(FILE *battary, FILE *command, int *code_list)
{
	create_command(command);
	int flag = 1;
	logo();
	while (flag == 1)
	{
		char c[100];
		printf("\n\t\tshell:> "); scanf("%s", &c);
		if (c == "w") {
			printf("Hello!\n");
		}
	}
}
void shell_command()
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
	system("cls");
	char text;
	for (int i = 0; i < 121; i++)
		fscanf(command, "%d", &code_list[i]);
	for (int i = 0; i < 121; i+=5) {
		printf("[%d] . %d\t[%d] . %d\t[%d] . %d\t[%d] . %d\t[%d] . %d\n", 
			i, code_list[i],
			i + 1, code_list[i + 1],
			i + 2, code_list[i + 2], 
			i + 3, code_list[i + 3],
			i + 4, code_list[i + 4]);
	}
	printf("\nNajmite lubyu klavishu dlya vihoda\nInput <ENTER> to be continue.\n");
	text = getch();
	switch(text)
	{
		case 8:
		{
			free(code_list);
			fclose(command);
			break;
		}
		case 13:
		{
			run_command(command, code_list);
		}
	}
}
void run_command(FILE *command, int *code_list)
{
	int flag = 1, j = 0;
	code_list = (int *)malloc(121 * sizeof(int));
	command = fopen("command_list.txt", "r");
	system("cls");
	printf("Viberete commandu iz spiska: \n");
	for (int i = 0; i < 121; i++)
		fscanf(command, "%d", &code_list[i]);
	for (int i = 0; i < 121; i++)
		printf("[%d] . %d\n", i, code_list[i]);
	while (flag == 1)
	{char text;
		system("cls");
		for (int i = 0; i < 121; i++) {
			if (j != i) {
				printf("[%d] . %d\n", i, code_list[i]);
			} else printf("[*] | [%d] . %d\n", i, code_list[i]);
		}
		printf("Input <ENTER> to be continue.\n");
		text = getch();
		switch(text)
		{
			case 13:
			{
				system("cls");
				printf("Vi deystvitelno hotite ispolsovat komandu [%d] . %d\n", j, code_list[j]);
				dict(command, code_list, j);
			}
			case 119:
			{
				j = j - 1;
				if (j < 0)
					j = 120;
			}
			case 115:
			{
				j++;
				if (j == 121)
					j = 0;
			}
		}
	}
}
void dict(FILE *command, int *code_list, int i)
{
	if ((i / 100 == 10) || (i % 100 == 10)) {

	}
	if ((i / 100 == 11) || (i % 100 == 11)) {
		
	}
	if ((i / 100 == 20) || (i % 100 == 20)) {
		
	}
	if ((i / 100 == 21) || (i % 100 == 21)) {
		
	}
	if ((i / 100 == 30) || (i % 100 == 30)) {
		
	}
	if ((i / 100 == 31) || (i % 100 == 31)) {
		
	}
	if ((i / 100 == 32) || (i % 100 == 32)) {
		
	}
	if ((i / 100 == 40) || (i % 100 == 40)) {
		
	}
	if ((i / 100 == 41) || (i % 100 == 41)) {
		
	}
	if ((i / 100 == 42) || (i % 100 == 42)) {
		
	}
	if ((i / 100 == 43) || (i % 100 == 43)) {
		
	}
}
void output_menu(int kursor)
{
	if (kursor == 0) 
		printf("\t\t[*] - Input Command\n\t\t - List Command\n\t\t - Run Command\n\t\t - Run Shell\n\t\t - Shutdown\n");
	if (kursor == 1) 
		printf("\t\t - Input Command\n\t\t[*] - List Command\n\t\t - Run Command\n\t\t - Run Shell\n\t\t - Shutdown\n");
	if (kursor == 2)
		printf("\t\t - Input Command\n\t\t - List Command\n\t\t[*] - Run Command\n\t\t - Run Shell\n\t\t - Shutdown\n");
	if (kursor == 3)
		printf("\t\t - Input Command\n\t\t - List Command\n\t\t - Run Command\n\t\t[*] - Run Shell\n\t\t - Shutdown\n");
	if (kursor == 4)
		printf("\t\t - Input Command\n\t\t - List Command\n\t\t - Run Command\n\t\t - Run Shell\n\t\t[*] - Shutdown\n");
}