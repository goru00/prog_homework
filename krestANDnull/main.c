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
int kursor_area_game(int **, int);
void output_kursor_area_game();

int main(int argc, char const *argv[])
{
	system("sudo apt-get install libncurses5-dev libncursesw5-dev");
	int **area = NULL;
	area = (int **)malloc(SIZE_N * sizeof(int));
	menu(area);
		system("clear");
		output_area_game(area);
		if (argc < 2) {
			printf("PORT NOT PROVIDED\n");
			exit(1);
		}
		int sockfd, newsockfd, portno, n = 0;
		char buffer[255];
		int move = 0;
		int make[9] = {0};
		struct sockaddr_in serv_addr, cli_addr;
		socklen_t clilen;
		sockfd = socket(AF_INET, SOCK_STREAM, 0);
		if (sockfd < 0) {
			error("Error opening Socket");
		}
		bzero((char *) &serv_addr, sizeof(serv_addr));
		portno = atoi(argv[1]);
		serv_addr.sin_family = AF_INET;
		serv_addr.sin_addr.s_addr = INADDR_ANY;
		serv_addr.sin_port = htons(portno);
		if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
			error("Failed bind");	
		listen(sockfd, 5);
		clilen = sizeof(cli_addr);
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		if (newsockfd < 0)
			error("Error accept\n");
		while(1)
		{
			system("clear");
			printf("Ожидаем ход соперника: \n");
			bzero(buffer, 4);
			output_area_game(area);
			while(n == 0)
			{
				n = read(newsockfd, buffer, 4);
			}
			system("clear");
			printf("Противник сделал ход: \n");
			sscanf(buffer, "%d", &make[move]);
			move = (make[move] / 10) % 10;
			bzero(buffer, 4);
			change_area_game(area, make, move);
			output_area_game(area);
			sleep(1);
			make[move + 1] = kursor_area_game(area, move + 1);
			sscanf(make[move + 1], "%s", &buffer);
			fgets(buffer, 4, stdin);
			n = write(newsockfd, buffer, strlen(buffer));
		}
		close(newsockfd);
		close(sockfd);
	return 0;
}
void area_game(int **area, int role)
{
	create_area_game(area);
}
void create_area_game(int **area)
{
	for (int i = 0; i < SIZE_N; i++)
		{
			area[i] = (int *)malloc(SIZE_M * sizeof(int));
			for (int j = 0; j < SIZE_M; j++)
				area[i][j] = 9;
		}
	for (int i = 1; i < SIZE_N - 1; i++)
	{
		for (int j = 1; j < SIZE_M - 1; j++)
		{
			area[i][j] = 0;
		}
	}
}
void change_area_game(int **area, int make[], int move)
{
	int n, m;
	for (int k = 0; k <= move; k++)
	{
		n = make[k] / 1000;
		m = (make[k] / 100) % 10;
		area[n][m] = 1;
	}
}
int kursor_area_game(int **area, int move)
{
	int flag = 1;
	char text;
	int i = 1, j = 1;
	while (flag == 1)
	{
		system("clear");
		initscr();
		printf("Ваш ход: \n");
		output_kursor_area_game(area, i, j);
		text = getch();
		switch(text)
		{
			case 32:
			{
				int res;
				res = (1000 * i) + (100 * j) + (10 * move) + 1;
				return res;
			}
			case 115:
			{
				if ((i >= 1) && (i <= SIZE_N - 1)) {
					i++;
					output_kursor_area_game(area, i, j);
				} else {
					i = 1;
				}
			}
			case 119:
			{
				if (i > 1) {
					i--;
					output_kursor_area_game(area, i, j);
				} else {
					i = 1;
				}
			}
			case 97:
			{
				if ((j > 1) && (j < SIZE_M - 1)) {
					j--;
					output_kursor_area_game(area, i, j);
				} else {
					j = 1;
				}
			}
			case 100:
			{
				if ((j >= 1) && (j <= SIZE_M - 1)) {
					j++;
					output_kursor_area_game(area, i, j);
				} else {
					j = 1;
				}
			}
		}
	}
	endwin();
}
void output_kursor_area_game(int **area, int n, int m)
{
	for (int i = 0; i < SIZE_N; i++)
	{
		for (int j = 0; j < SIZE_M; j++)
		{
			if ((i == n) && (j == m)) {
				printf("*");
			} 
			else if (area[i][j] == 0) {
				printf(" ");
			}
			else if (area[i][j] == 1) {
				printf("X");
			}
			else if (area[i][j] == 2) {
				printf("O");
			}
			else if (area[i][j] == 9) {
				printf("%d", area[i][j]);
			}
		}
		printf("\n");
	}
}
void output_area_game(int **area)
{
	for (int i = 0; i < SIZE_N; i++) 
	{
		for (int j = 0; j < SIZE_M; j++) 
		{
			if (area[i][j] == 0) {
				printf(" ");
			} else if (area[i][j] == 9) printf("%d", area[i][j]);
			if (area[i][j] == 1) {
				printf("X");
			} else if (area[i][j] == 2) printf("O");
		}
		printf("\n");
	}
}
void menu(int **area)
{
	int flag = 1;
	int i = 0;
	char text;
	while(flag == 1)
	{
		printf("K R E S T  AND  N U L L\n");
		printf("Peredvigatsya s pomochiu W(vverh) i S(vniz): \n");
		printf("Menu: \n");
		output_menu(i);
		initscr();
		text = getch();
		switch(text)
		{
			case 32:
			{
				int point = i;
				if (point == 0){
					system("clear");
					area_game_menu(area);
					flag = 0;
					break;
				}
				if (point == 1)
					//Records(file);
				if (point == 2)
					exit(1);
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
	endwin();
}
void area_game_menu(int **area)
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
					flag = 0;
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