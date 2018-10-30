#include<stdio.h>
#include<stdlib.h>
int main()
{
	int A = -2, B = -1;
	while (A < B)
	{
		system("clear");
		printf("Введите число А: ");
		scanf("%d", &A);
		printf("Введите число В: ");
		scanf("%d", &B);
		if (A > B)
			break;
	}
	if (A < 0)
		A *=(-1);
	if (B < 0)
		B *=(-1);
	
	return 0;
}