#include<stdio.h>
#include<stdlib.h>
int find(char *, FILE *, int);
void fclear();
int main()
{
	char *array;
	int n = 0, k;
    FILE *file = fopen("text", "r+");
    array = (char *)malloc(n * sizeof(char));
    k = find(array, file, n);
    fclear(array, file, k);
    return 0;
}
void fclear(char *mass, FILE *file, int count)
{
	file = fopen("text", "r+");
	printf("%d\n", count);
	rewind(file);
	for (int i = 0; i < count; i++)
	{
		fprintf(file, "%s", "s");
	}
}
int find(char *mass, FILE *file, int count)
{
    while (!feof(file))
    {
    	count = fgetc(file);
    	fscanf(file, "%s", mass);
    	if (mass == "\0"){
    		fclose(file);
    		break;
    	}
    	count++;
    }
    printf("%s\n\n", mass);
    return count;
}