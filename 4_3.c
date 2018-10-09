#include<stdio.h>

int main()
{
	for (int str = 1; str <= 13; str++)
	{
		if (str <= 7) {
			for (int x = 1; x <=str; x++)
			{
				printf("*");
			}
			printf("\n");
		} else {
			for (int x = 6; x >= str - 7; x--)
			{
				printf("*");
			}
			printf("\n");
		}
		
	}
	return 0;
}