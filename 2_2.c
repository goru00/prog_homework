#include<stdio.h>

main()
{
	
	int a, b, c;
	int max = 0;
	int min = 0;
	int sr = 0;
	printf("Введите целые числа: \n"); scanf("%d\n%d\n%d", &a, &b, &c);

	system("clear");

	if ((a > b) && (a < c)) {
		max = c;
		min = b;
		sr = a;
		printf("%d\n%d\n%d\n", min, sr, max);
	}
	else if ((b > a) && (b < c)) {
		max = c;
		sr = b;
		min = a;
		printf("%d\n%d\n%d\n", min, sr, max);
	}
	else if ((c > a) && (c < b)) {
		max = b;
		sr = c;
		min = a;
		printf("%d\n%d\n%d\n", min, sr, max);
	}
	else if ((c > b) && (c < a)) {
		max = a;
		sr = c;
		min = b;
		printf("%d\n%d\n%d\n", min, sr, max);
	}
	else if ((b > a) && (a > c)) {
		max = b;
		sr = a;
		min = c;
		printf("%d\n%d\n%d\n", min, sr, max);
	}
	else if ((a == b) && (a < c)) {
		printf("%d\n%d\n%d\n", a, b, c);
	}
	else if ((a == b) && (a > c)) {
		printf("%d\n%d\n%d\n", c, a, b);
	}
	else if ((a == c) && (a < b)) {
		printf("%d\n%d\n%d\n", a, c, b);
	}
	else if ((a == c) && (a > b)) {
		printf("%d\n%d\n%d\n", b, a, c);
	}
	else if ((b == c) && (b < a)) {
		printf("%d\n%d\n%d\n", a, b, c);
	}
	else if ((b == c) && (b > a)) {
		printf("%d\n%d\n%d\n", b, c, a);
	}
	else if ((a == b) && (b == c) && (a == c)) {
		printf("%d\n%d\n%d\n", a, b, c);
	}

	return 0;
}