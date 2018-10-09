#include<stdio.h>

int main()
{
	int a;
	printf("Введите высоту пирамиды: ");
	scanf("%d", &a);
	for (int str = 1; str <= (a * 2) - 1; str++)
	{
		if (str <= a) {
			for (int x = 1; x <=str; x++)
			{
				printf("*");
			}
			printf("\n");
		} else {
			for (int x = (a - 1); x >= str - a; x--)
			{
				printf("*");
			}
			printf("\n");
		}
		
	}
	return 0;
}