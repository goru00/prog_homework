#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
int i = 0, j = 0, i_start = 0, i_end = 2;
int area[3][3] = {0};
void game()
{
	int flag = 1, hum;
	while (flag == 1)
	{
		joy(&flag);
		output(i_end);
	}
	system("cls");
	printf("Выбрано: %d %d\n", i, j);
}
void output()
{
	for (int k = 0; k < i_end + 1; k++) {
		for (int p = 0; p < i_end + 1; p++)
		{
			if ((i == k) && (p == j)) {
				printf("\t*");
			} else if (area[k][p] == 0) {
				printf("\t+");
			} else if (area[k][p] == 1) {
				printf("\tX");
			} else if (area[k][p] == 2) {
				printf("\tO");
			}
		}
		printf("\n");
	}
	printf("Dlya vihoda najmite ESC\n\n\n");
}
void test_area()
{
	int k = 0;
	for (int i = 0; i < i_end + 1; i++) {
		for (int j = 0; j < i_end + 1; j++) {
			if (area[i][j] != 0)
				k++;
		}
	}
	if (k == 9) {
		printf("NICHYA, POCONI\nDAVAITE PO NOVOY\n");
		sleep(2);
		game();
	}
}
void marker()
{
	if (area[i][j] == 0) {
		area[i][j] = 1;
	} else {
		system("cls");
		printf("NELZYA!\nDlya prodoljeniya najmite lubyu klavishu\n");
		game();
	} 
	test_area();
	int flag = 1, i_comp, j_comp;
	while (flag == 1)
	{
		i_comp = (rand() % 3); j_comp = (rand() % 3);
		if (area[i_comp][j_comp] == 0) {
			area[i_comp][j_comp] = 2;
			flag = 0;
		}
	}
	system("cls");
	test_area();
}
/*void test()
{

}*/
int joy(int *flag)
{
	char select = getch();
	switch(select)
	{
		case 13:
		{
			system("cls");
			marker();
			return i;
		}
		case 27:
		{
			*flag = 0;
		}
		case 119: // вверх
		{
			if (i == i_start) {
				i = i_end;
				//output_menu(i);
				system("cls");
				return i;
			} 
			if (i > i_start) {
				i--;
				//output_menu(i);
				system("cls");
				return i;
			}
		}
		case 115: // вниз
		{
			if (i == i_end) {
				i = i_start;
				//output_menu(i);
				system("cls");
				return i;
			} else {
				i++;
				//output_menu(i);
				system("cls");
				return i;
			}
		}
		case 100: // вправо
			{
				if (j == i_end) {
					j = i_start;
					system("cls");
				} else {
					j++;
					system("cls");
				}
				j++;
			}
		case 97: // влево
		{
			if (j <= i_start) {
				j = i_end;
				system("cls");
			} else {
				j--;
				system("cls");
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
	srand(time(NULL));
	game();
	return 0;
}