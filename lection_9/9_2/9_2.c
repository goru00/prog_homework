#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *file = fopen("text", "a+");
    find(file);
    return 0;
}
void find(FILE *file)
{
    int k = 0;
    while ((fgetc(file)) != "\0")
        k++;
    for (int i = 0; i < k; k++)
        fprintf(file, "");
}