#include<stdio.h>

main() 
{
	
	float a1, a2, a3, a4, end_numb = 0;
	int sum;
	printf("Введите 4 числа: \n"); scanf("%f\n%f\n%f\n%f", &a1, &a2, &a3, &a4);

	sum = a1 + a2 + a3 + a4;

	end_numb = sum % 10;
	printf("Последняя цифра суммы: %.0f\n", end_numb);

	return 0;
}

