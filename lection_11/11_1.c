#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
int tolower(int c);
int toupper(int c);
void invers(char *);
int main()
{
	char mass[100];
	printf("Введите строку: "); scanf("%s", mass);
	invers(mass);
	return 0;
}
void invers(char *mass)
{
	int i = 0, c;
	for (int i = 0; i < 100; i++) {
		c = mass[i];
		if ((mass[i] >= 'a') && (mass[i] <= 'z')) {
			mass[i] = toupper(c);
		} else if ((mass[i] >= 'A') && (mass[i] <= 'Z'))
			mass[i] = tolower(c);
	}
	printf("%s\n", mass);
}