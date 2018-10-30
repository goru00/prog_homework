#include<stdio.h>

int main()
{
	int A = 0, k = 1;
	float sum = 1;
	while (A <= 1)
	{
	     printf("Введите число А: ");
	     scanf("%d", &A);
	     if (A > 1)
	         break;
	}
	while (A > 0)
	{
		 k +=1;
		 sum +=(1.0/k);
		 if (sum >= A)
		 {
		 	sum -= (1.0/k);
		 	k -= 1;
		 	break;
		 }
	}
	printf("Число К равно: %d\n", k);
	printf("Сумма равна: %f\n", sum);
	return 0;
}
		     