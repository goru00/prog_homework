#include<stdio.h>

main()
{
	int year;
	int year4, year100;
	printf("Какой сейчас год?: "); scanf("%d", &year);
	year4 = year % 4;
	year100 = year % 100;
	system("clear");
	if ((year4 == 0) && (year100 == 0)) {
		printf("Это високосный год!\n");
	} else printf("Это обычный год.\n");
	return 0;
}