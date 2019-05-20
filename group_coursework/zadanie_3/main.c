#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include <windows.h>
int i_menu = 0, i = 0, j = 0, i_start = 0, i_end_menu = 4;
void menu()
{
	int i = 0, flag = 1;
	i_menu = 0; i_start = 0;
	while (flag == 1)
	{
		logo();
		output_menu(i_menu);
		joy_menu(&flag);
	}
	if (i_menu == 0) {
		new_note();
	}
	if (i_menu == 4)
		exit(1);
	if (i_menu == 3) {
		printf("\n");
		printf("Najmite <BACKSPACE>, chtobi vernutsya obratno v menu\n");
		printf("\n");
		show_note();
	}
}
void new_note()
{
	FILE *data = fopen("database.txt" , "a+");
	char note[100], datanote[100] = "| Note: ";
	printf("Note: "); scanf("%s", note);
	i_menu = 2;
	int flag = 1, flag_num, day = 0, month = 0, year = 1970;
	system("cls");
	printf("| Note: %s |\n| Date: [%d:00:00] |", note, day);
	while (flag == 1) { // число
		flag_num = i_menu;
		joy_menu(&flag);
		if (flag_num < i_menu) {
			day--; 
			if (day < 0) {
				day = 30;
			}
		} else if (flag_num > i_menu) {
			day++;
			if (day > 30) {
				day = 0;
			}
		}
		i_menu = 2;
		printf("| Note: %s |\n| Date: [%d:00:00] |", note, day);
	}
	flag = 1;
	system("cls");
	printf("| Note: %s |\n| Date: [%d:00:00] |", note, day);
	i_menu = 2;
	while (flag == 1) { // месяц
		flag_num = i_menu;
		joy_menu(&flag);
		if (flag_num < i_menu) {
			month--;
			if (month < 0) {
				month = 12;
			}
		} else if (flag_num > i_menu) {
			month++;
			if (month > 12) {
				month = 0;
			}
		}
		i_menu = 2;
		printf("| Note: %s |\n| Date: [%d:%d:00] |", note, day, month);
	}
	flag = 1;
	system("cls");
	printf("| Note: %s |\n| Date: [%d:%d:00] |", note, day, month);
	i_menu = 2;
	while (flag == 1) { // год
		flag_num = i_menu;
		joy_menu(&flag);
		if (flag_num < i_menu) {
			year--;
			if (year < 1970) {
				year = 1970;
			}
		} else if (flag_num > i_menu) {
			year++;
		}
		i_menu = 2;
		printf("| Note: %s |\n| Date: [%d:%d:%d] |", note, day, month, year);
	}
	char *s_day, *s_month, *s_year;
	sprintf(s_day, "%d", day);
	int k = 0;
	for (; datanote[k] != '\0'; k++) 
	for (int i = 0; note[i] != '\0'; i++, k++) {
		datanote[k] = note[i];
	}
	printf("%s\n", datanote);
	if (day > 10) {
		datanote[8] = *s_day;
	} else if (day < 10) {

	}
}
void show_note()
{
	FILE *data = fopen("database.txt" , "r+");
	int flag = 1;
	char mass[100];
	while(fgets(mass, 100, data))
	{
		if (mass[strlen(mass) - 1] == '\n') {
			mass[strlen(mass) - 1] = '\0';
		}
		printf("%s\n", mass);
	}
	if (getch() == 8) {
		fclose(data);
		menu();
	} else if (getch != 8) {
		show_note(data);
	}
}
void logo()
{
	system("cls");
	printf("\t\t\tEJEDNEVNIK  I V T ESHNIKA\n");
	printf("\t\tMenu: \n");
}
void output_menu(int kursor)
{
	if (kursor == 0) 
		printf("\t\t[*] - New Note\n\t\t - Edit Note\n\t\t - Delete Note\n\t\t - Show Note's\n\t\t - Shutdown\n");
	if (kursor == 1) 
		printf("\t\t - New Note\n\t\t[*] - Edit Note\n\t\t - Delete Note\n\t\t - Show Note's\n\t\t - Shutdown\n");
	if (kursor == 2) 
		printf("\t\t - New Note\n\t\t - Edit Note\n\t\t[*] - Delete Note\n\t\t - Show Note's\n\t\t - Shutdown\n");
	if (kursor == 3) 
		printf("\t\t - New Note\n\t\t - Edit Note\n\t\t - Delete Note\n\t\t[*] - Show Note's\n\t\t - Shutdown\n");
	if (kursor == 4) 
		printf("\t\t - New Note\n\t\t - Edit Note\n\t\t - Delete Note\n\t\t - Show Note's\n\t\t[*] - Shutdown\n");
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
				i_menu = i_end_menu;
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
			if (i_menu == i_end_menu) {
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
int main()
{
	menu();
	return 0;
}