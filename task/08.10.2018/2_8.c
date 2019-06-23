#include<stdio.h>

main()
{

	float x, f;

	printf("Введите значение x: "); scanf("%f", &x);
	system("clear");
	if ((x < -2) || (x > 2)) {
		f = 2 * x;
		printf("Значение функции равно: %.1f\n", f);
	} else if ((x == -2) || (x == 2)) {
		f = (-3) * x;
		printf("Значение функции равно: %.1f\n", f);
	} else if ((x > -2) || (x < 2)) {
		f = 5 * x;
		printf("Значение функции равно: %.1f\n", f);
	}

}

