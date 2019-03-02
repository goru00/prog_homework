#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
void ver(int *, int *);
int main()
{
	srand(time(NULL));
	int turttle[] = {1,1,1,1,1,2,2,3,3,3};
	int bunny[] = {1,1,2,2,3,4,4,4,5,5};
	ver(turttle, bunny);
	return 0;
}
int start_run_t(int turt)
{
	int sum;
	switch(turt)
	{
		case 1:
			printf("черепаха: тащится быстро\n");
			return 3;
		case 2:
			printf("черепаха: сползание\n");
			return -6;
		case 3:
			printf("черепаха: тащится медленно\n");
			return 1;
	}
}
int start_run_b(int bun)
{
	int sum;
	switch(bun)
	{
		case 1:
			printf("заяц: спячка\n");
			return 0;
		case 2: 
			printf("заяц: большой прыжок\n");
			return 9;
		case 3:
			printf("заяц: большое сползание\n");
			return -12;
		case 4:
			printf("заяц: малый прыжок\n");
			return 1;
		case 5:
			printf("заяц: малое сползание\n");
			return -2;
	}
}
void ver(int *m_turttle, int *m_bunny)
{
	int turttle = 0;
	int bunny = 0;
	int pos_t;
	int pos_b;
	while ((turttle < 70) || (bunny < 70))
	{
		pos_t = (rand() % 10);
		pos_b = (rand() % 10);
		pos_t = m_turttle[pos_t];
		pos_b = m_bunny[pos_b];
		turttle += start_run_t(pos_t);
		if (turttle < 0)
			turttle = 0;
		printf("черепаха: %d\n", turttle);
		bunny += start_run_b(pos_b);
		if (bunny < 0)
			bunny = 0;
		printf("заяц: %d\n", bunny);
		if (bunny >= 70){
			printf("\nПобеда зайца\n");
			break;
		}
		if (turttle >= 70){
			printf("\nПобеда черепахи\n");
			break;
		}
	}
}