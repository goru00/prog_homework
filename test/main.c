#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void bigram(char *, char *);
void bigram(char *line_one, char *line_two)
{
	
} 
int main()
{
	char line_one[100], line_two[100];
	printf("Введите первую строку: "); scanf("%s", line_one);
	printf("Введите вторую строку: "); scanf("%s", line_two);
	if (strlen(line_one) != strlen(line_two)) {
		if ((strlen(line_one) % 2 == 0) || (strlen(line_two) % 2 == 0)) printf("ERROR\n");
	} else bigram(line_one, line_two);
	return 0;
}