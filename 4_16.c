#include<stdio.h>

int main()
{
	int F1 = 1, F2 = 1, k, N = 0,Fi,Finew,Fipos;
	while (N <= 1)
	{
		printf("Введите число N: ");
		scanf("%d", &N);
		if (N > 1)
		break;
	}
	printf("F(1) = %d\nF(2) = %d\n", F1, F2);
	if (N > 2)
	{
		Fi = F1 + F2;
		printf("F(3) = %d\n", Fi);
		Fipos = F2;
		for (k = 4; k <= N; k++)
		{
			Finew = Fipos + Fi;
			printf("F(%d) = %d\n", k, Finew);
			Fipos = Fi; 
			Fi = Finew;
		}
		return 0;
	}
}
	