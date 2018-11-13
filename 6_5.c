//commit reset
#include<stdlib.h>
#include<stdio.h>
#define VALUE 9
int main()
{
    int k, count = 0;
    printf("Введите значение k: "); scanf("%d", &k);
	int a[VALUE + k];
	srand(time(NULL));
	for (int i = 0; i <= VALUE; i++)
    {
    	a[i] = (rand() % 100) + 1;
        printf("a[%d] = %d\n", i, a[i]);
    }
	printf("\n");
    count = k;
    for (int i = 0; i <= VALUE; i++)
    {
        for (int j = k; j <= VALUE + k; j++)
        {
            a[j] = a[i];
            printf("a[%d] = %d\n", count, a[j]);
            break;
        }
        count++;
    }
    return 0;
}