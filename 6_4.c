//commit reset
#include<stdlib.h>
#include<stdio.h>
#define VALUE 10
int main()
{
	int a[VALUE], k = 1;
    int b[VALUE + 1];
	srand(time(NULL));
	for (int i = 0; i <= VALUE - 1; i++)
    {
    	a[i] = (rand() % 100) + 1;
        printf("a[%d] = %d\n", i, a[i]);
    }
	printf("\n");
    //k +=VALUE;
    for (int i = 0; i < VALUE; i++)
    {
        b[i+1] = a[i];        
        printf("a[%d] = %d\n", i + 1, b[i+1]);
    } 
    return 0;
}