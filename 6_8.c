#include<stdio.h>
#include<stdlib.h>
#define VALUE 9
int a[VALUE];
int small(int count, int num);

int small(int count, int num)
{
    for (int i = 0; i <= VALUE; i++)
    {
        if ((num / 10) > 0) {
            if ((a[i] % 100) == ((num % 100) - count)) 
                printf("a[%d] = %d\n", i, a[i]);
                return 0;
        } else {
            if ((a[i] % 100) == ((num % 100) - count))
                printf("a[%d] = %d\n", i, a[i]);
                return 0;
        }
    }
    if (count == 0)
        count++;
    return count;
}

int main()
{
    int x;
    printf("Введите число x: "); scanf("%d", &x);
    int k = 0;
    for (int i = 0; i <= VALUE; i++)
    {
        a[i] = (rand() % 100) + 1;
        printf("a[%d] = %d\n", i, a[i]);
    }
    srand(time(NULL));
    if (k == 0)
        small(k, x);
}