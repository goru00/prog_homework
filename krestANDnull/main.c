#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<ncurses.h>

#define SIZE_N 5
#define SIZE_M 5

void area_game();
void create_area_game();
void output_area_game();
void menu();
void area_game_menu();
void output_menu();
void output_area_game_menu();

int main(int argc, char const *argv[])
{
	system("sudo apt-get install libncurses5-dev libncursesw5-dev");
	char **area = NULL;
	area = (char **)malloc(SIZE_N * sizeof(char));
	menu(area);
	return 0;
}
void area_game(char **area, int role)
{
	create_area_game(area);
	if (role == 2) { // host

	}
	if (role == 1) { // client

	}
	if (role == 0) { // computer

	}
}
void create_area_game(char **area)
{
	for (int i = 0; i < SIZE_N; i++)
	{
		area[i] = (char *)malloc(SIZE_M * sizeof(char));
		for (int j = 0; j < SIZE_M; j++)
		{
			area[i][j] = 0;
		}
	}
}
void output_area_game(char **area)
{
	for (int i = 0; i < SIZE_N; i++) {
		for (int j = 0; j < SIZE_M; j++) {
			printf("%s", area[i][j]);
		}
		printf("\n");
	}
}
void menu(char **area)
{
	int flag = 1;
	int i = 0;
	char text;
	initscr();
	while(flag == 1)
	{
		printf("K R E S T  AND  N U L L\n");
		printf("Peredvigatsya s pomochiu W(vverh) i S(vniz): \n");
		printf("Menu: \n");
		output_menu(i);
		text = getch();
		switch(text)
		{
			case 32:
			{
				int point = i;
				if (point == 0){
					system("clear");
					area_game_menu(area);
					break;
				}
				if (point == 1)
					//Records(file);
				if (point == 2)
					flag = 0;
			}
			case 119:
			{
				if (i == 0) {
					i = 2;
					output_menu(i);
					system("clear");
				} 
				if (i > 0) {
					i--;
					output_menu(i);
					system("clear");
				}
			}
			case 115:
			{
				if (i == 2) {
					i = 0;
					output_menu(i);
					system("clear");
				} else {
					i++;
					output_menu(i);
					system("clear");
				}
			}
		}
	}
}
void area_game_menu(char **area)
{
	int flag = 1;
	int i = 0;
	char text;
	while(flag == 1)
	{
		printf("K R E S T  AND  N U L L\n");
		printf("Peredvigatsya s pomochiu W(vverh) i S(vniz): \n");
		printf("Menu: \n");
		output_area_game_menu(i);
		text = getch();
		switch(text)
		{
			case 32:
			{
				int point = i;
				if (point == 0) {
					system("clear");
					int role = 2; // host
					area_game(area, role);
					break;
				}
				if (point == 1) {
					system("clear");
					int role = 1; // client
					area_game(area, role);
					break;
				}
				if (point == 2) {
					system("clear");
					int role = 0; // computer
					area_game(area, role);
					break;
				}
				if (point == 3) {
					system("clear");
					flag = 0;
				}
			}
			case 119:
			{
				if (i == 0) {
					i = 3;
					output_area_game_menu(i);
					system("clear");
				} 
				if (i > 0) {
					i--;
					output_area_game_menu(i);
					system("clear");
				}
			}
			case 115:
			{
				if (i == 3) {
					i = 0;
					output_area_game_menu(i);
					system("clear");
				} else {
					i++;
					output_area_game_menu(i);
					system("clear");
				}
			}
		}
	}
}
void output_area_game_menu(int kursor)
{
	if (kursor == 0) 
		printf("[*] - Play on Host\n - Play on Client\n - Play on Computer\n - Back\n");
	if (kursor == 1) 
		printf(" - Play on Host\n[*] - Play on Client\n - Play on Computer\n - Back\n");
	if (kursor == 2) 
		printf(" - Play on Host\n - Play on Client\n[*] - Play on Computer\n - Back\n");
	if (kursor == 3) 
		printf(" - Play on Host\n - Play on Client\n - Play on Computer\n[*] - Back\n");
}
void output_menu(int kursor)
{
	if (kursor == 0) 
		printf("[*] - New Game\n - Records\n - Exit\n");
	if (kursor == 1) 
		printf(" - New Game\n[*] - Records\n - Exit\n");
	if (kursor == 2)
		printf(" - New Game\n - Records\n[*] - Exit\n");
}