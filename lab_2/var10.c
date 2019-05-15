#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void inputspace(char *text)
{
	int i = 0, lenght = strlen(text);
	char *mass;
	while (text[i] != '\0')
	{
		if (text[i] == ' ')
			lenght++;
		i++;
	}
	mass = (char *)malloc(lenght * sizeof(char));
	i = 0;
	int k = 0;
	do 
	{
		if (text[i] == ' ') {
			mass[k] = text[i];
			mass[k + 1] = ' ';
			i++;
			k+=2;
		} else if (text[i] != ' ') {
			mass[k] = text[i];
			i++;
			k++;
		}
	} while(text[i] != '\0');
	i = 0;
	while (mass[i] != '\0')
	{
		printf("%c", mass[i]);
		i++;
	}
}
int main(int argc, char const *argv[])
{
	char text[] = "Mama mila ramu";
	inputspace(text);
	return 0;
}