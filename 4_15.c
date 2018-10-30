#include<stdio.h>

int main()
{
	int N = -1, i;
	while (N <= 0)
	{
		printf("Введите число N: ");
		scanf("%d", &N);
		if (N > 0)
		    break;
	}
	i = N;
	for (N = 0; i >=1;i--)
	{
		N =N + (2 * i - 1);
	}
	printf("Число N равно: %d", N);
	
	
	return 0;
}