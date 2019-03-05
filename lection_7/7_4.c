#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define SIZE_CARTOONS 13
#define SIZE_MAST 4
void output();
void input();
void tass();
int main()
{
	srand(time(NULL));
	int position[SIZE_MAST * SIZE_CARTOONS];
	char cartoons[SIZE_CARTOONS][100] = {
		"Туз",
		"Двойка",
		"Тройка",
		"Четверка",
		"Пятерка",
		"Шестерка",
		"Семерка",
		"Восьмерка",
		"Девятка",
		"Десятка",
		"Валет",
		"Дама",
		"Король"
	};
	char mast[SIZE_MAST][100] = {
		"Черви",
		"Бубны",
		"Трефы",
		"Пики"
	};
	output((char *)cartoons, (char *)mast);
	input(position);
	tass(position, (char *)cartoons, (char *)mast);
	return 0;
}
void input(int *mass) 
{
	int count = 0;
	for (int i = 0; i < SIZE_MAST * SIZE_CARTOONS; i++)
	{
		mass[i] = count;
		count++;
	}
}
void output(char card[][100], char name[][100])
{
	printf("Все карты: \n");
	for (int i = 0; i < SIZE_CARTOONS; i++)
		for (int j = 0; j < SIZE_MAST; j++)
			printf("%s %s\n", card[i], name[j]);
}
void tass(int *mass, char card[][100], char name[][100])
{
	int ver;
	int count = 0;
	printf("\n Перетасовываем: \n");
	while (count + 1 < SIZE_CARTOONS * SIZE_MAST)
	{
		ver = (rand() % 52);
		//printf("Позиция: %d\nЗначение: %d\n", ver, mass[ver]);
		if (mass[ver] != 0)
		{
			if ((ver <= 12) && (ver >= 0)) {
				printf("%s %s\n", card[ver], name[0]);
				mass[ver] = 0;
				count++;
			}
			if ((ver <= 25) && (ver > 12)) {
				printf("%s %s\n", card[ver % SIZE_CARTOONS], name[1]);
				mass[ver] = 0;
				count++;
			}
			if ((ver <= 38) && (ver > 25)) {
				printf("%s %s\n", card[ver % SIZE_CARTOONS], name[2]);
				mass[ver] = 0;
				count++;
			}
			if ((ver <= 51) && (ver > 38)) {
				printf("%s %s\n", card[ver % SIZE_CARTOONS], name[3]);
				mass[ver] = 0;
				count++;
			}
		}
		if ((mass[0] == 0) && (ver == 0))
			printf("%s %s\n", card[0], name[0]);
	}
}