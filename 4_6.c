#include<stdio.h>

int main()
{
	int i;
	for (i = 1; i <= 7; i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for (i = 3; i <= 23; i +=5)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 19; i <= 51; i +=8)
	{
		printf("%d ", i);
	}
	return 0;
}