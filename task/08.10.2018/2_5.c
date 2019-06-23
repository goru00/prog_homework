#include<stdio.h>

main()
{

	float A, B, C;
	printf("Введите 3 числа: \n"); scanf("%f\n%f\n%f", &A, &B, &C);
	system("clear");

	if ((A < B) && (B < C)) {
		A *= 2;
		B *= 2;
		C *= 2;
		printf("%f\n%f\n%f\n", A, B, C);
	}
	if ((A > B) || (B > C)) {
		A = A * (-1); 
		B = B * (-1); 
		C = C * (-1); 
		printf("%.0f\n%.0f\n%.0f\n", A, B, C); 
	}

	return 0;
}

