#include<stdio.h>
#include<stdlib.h>
void menu();
void output_menu();
int main()
{
	srand(time(NULL));
	int **enemy_lab = NULL, **ally_lab = NULL;
	menu(enemy_lab, ally_lab);
	return 0;
}
void menu(int **enemy_lab, int **ally_lab)
{
	int flag = 1;
	int i = 0;
	char select;
	while(flag == 1)
	{
		system("clear");
		printf("\t\tW A R S H I P S\n");
		printf("\t\tPeredvigatsya s pomochiu W(vverh) i S(vniz): \n");
		printf("\t\t\tMenu: \n");
		output_menu(i);
		system("stty raw");
		select = getchar();
		switch(select)
		{
			case 32:
			{
				int point = i;
				if (point == 0){
					start_game(enemy_lab, ally_lab);
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
		system("stty cooked");
	}
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