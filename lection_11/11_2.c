#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
void loli(char *loli)
{
	int a, i = 0;
	while (loli[i] != '\0') {
		a=loli[i];
		if(isalpha(a) == 0) 
			loli[i]=' ';
		i++;
	}
	printf("%s\n",loli);
}

int main()
{
	char mass[100];
	printf("Введите строку: "); scanf("%s", mass);
	loli(mass);
	return 0;
}