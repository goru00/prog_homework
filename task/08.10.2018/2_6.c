#include<stdio.h>

main()
{
	float OX, OY;
	printf("Введите точки OX и OY: \n"); scanf("%f\n%f", &OX, &OY);

	system("clear");

	if ((OX > 0) && (OY > 0)) {
		printf("Точка находится в I четверти.\n");
	}
	if ((OX < 0) && (OY > 0)) {
		printf("Точка находится в II четверти.\n");
	}
	if ((OX < 0) && (OY < 0)) {
		printf("Точка находится в III четверти.\n");
	}
	if ((OX > 0) && (OY < 0)) {
		printf("Точка находится в IV четверти.\n");
	}

	return 0;

}

