#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * search(char *text)
{ 
	char *str_word = (char *)malloc(2 * sizeof(char));

	str_word[0] = str_word[1] = 0;
	int c, i = 0;
		do 
		{
			c = text[i];
			if ((text[i] >= 'a') && (text[i] <= 'z'))
				str_word[0]+=1;
			else if ((text[i] >= 'A') && (text[i] <= 'Z'))
				str_word[1]+=1;
			i++;
		} while (c!='\0');
		return str_word;
}
int main(int argc, char const *argv[])
{
	char text[] = "            Mama mila ramu Vot tak vot? ";
	char *a = search(text);
	printf("Кол-во строчных букв в строке: %d\tКол-во прописных букв в строке: %d\n", a[0], a[1]);
	return 0;
}