#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int input(FILE *);
void finput();
int main()
{
	int count;
	srand(time(NULL));
	FILE *frandom = fopen("frandom", "w+");
	count = input(frandom);
	FILE *output = fopen("output", "w+");
	fclose(frandom);
	finput(frandom, count);
	return 0;
}
void finput(FILE *output, int k)
{
	output = fopen("frandom", "r+");
	int mass;
	fscanf(output, "%d", mass);
	printf("%d\n", mass);
}
int input(FILE *frandom)
{
	int size = (rand() % 20) + 1, i;
	for (i = 0; i < size; i++)
	{
		fprintf(frandom, "%d", (rand() % 10));
	}
	return i;
}