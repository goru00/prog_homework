#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
void loli(char *loli)
{
	int a, i = 0, k = 0;
	while (loli[i] != '\0') {
		a=loli[i];
		if(!isdigit(a) == 0) {
			loli[k] = loli[i];
			k++;
		}
		i++;
	}
	while (loli[k] != '\0') {
		loli[k] = ' ';
		k++;
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