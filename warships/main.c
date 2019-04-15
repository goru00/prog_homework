#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
int main()
{
	srand(time(NULL));
	int **enemy_lab = NULL, **ally_lab = NULL;
	menu(enemy_lab, ally_lab);
	return 0;
}
void start_game(int **enemy_lab, int **ally_lab)
{

}
void menu(int **enemy_lab, int **ally_lab)
{
	int flag = 1;
	int i = 0;
	char text;
	while(flag == 1)
	{
		printf("\t\tW A R S H I P S\n");
		printf("Peredvigatsya s pomochiu W(vverh) i S(vniz): \n");
		printf("Menu: \n");
		output_menu(i);
		//text = getch();
		switch(text)
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
				if (i == 2) {
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
void output_menu(int kursor)
{
	if (kursor == 0) 
		printf("[*] - New Game\n - Records\n - Exit\n");
	if (kursor == 1) 
		printf(" - New Game\n[*] - Records\n - Exit\n");
	if (kursor == 2)
		printf(" - New Game\n - Records\n[*] - Exit\n");
}