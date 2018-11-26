#include<stdio.h>
#include<stdlib.h>
#define VALUE 9

int a[VALUE];

void sort();
int one();

int one()
{
    int max = a[VALUE], min = a[0], x, sum = 0;
    for (int i = 0; i <= VALUE; i++)
    {
        sum += a[i];
    }
    int srd = sum / VALUE;
    printf("%d\n", srd);
    printf("Введите число x: "); scanf("%d", &x);
    if (x / 10 != 0) {
        if (x % 10 == )
    }
    return 0;
}
void sort()
{
    int min, index_min;
    for (int i = 0; i < VALUE; i++)
    {
        min = a[i];
        index_min = i;
        for (int j = i; j <= VALUE; j++)
            if (min > a[j]) 
            {
                min = a[j];
                index_min = j;
            }
        a[index_min] = a[i];
        a[i] = min;
    }
    for (int i = 0; i <= VALUE; i++)
    {
        //a[i] = (rand() % 100) + 1;
        printf("a[%d] = %d\n", i, a[i]);
    }
    one();
}
int main()
{
    srand(time(NULL));
    for (int i = 0; i <= VALUE; i++)
    {
        a[i] = (rand() % 100) + 1;
    }
    sort();
    return 0;
}