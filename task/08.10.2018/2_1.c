#include<stdio.h>

main() 
{
	float a1, a2, a3, a4, a5;
	printf("Введите 5 чисел: \n"); scanf("%f%f\n%f\n%f\n%f", &a1, &a2, &a3, &a4, &a5);
	int k_pol = 0;
	int k_men = 0;
	int k_null = 0;

	system("clear");

	if (a1 > 0)
		k_pol +=1;
	else if (a1 < 0)
		k_men +=1;
	else if (a1 == 0)
		k_null +=1;
	if (a2 > 0)
		k_pol +=1;
	else if (a2 < 0)
		k_men +=1;
	else if (a2 == 0)
		k_null +=1;
	if (a3 > 0)
		k_pol +=1;
	else if (a3 < 0)
		k_men +=1;
	else if (a3 == 0)
		k_null +=1;
	if (a4 > 0)
		k_pol +=1;
	else if (a4 < 0)
		k_men +=1;
	else if (a4 == 0)
		k_null +=1;
	if (a5 > 0)
		k_pol +=1;
	else if (a5 < 0)
		k_men +=1;
	else if (a5 == 0)
		k_null +=1;

	printf("Чисел больше 0 = %d\n", k_pol);
	printf("Чисел меньше 0 = %d\n", k_men);
	printf("Чисел равных 0 = %d\n", k_null);
	return 0;
}

