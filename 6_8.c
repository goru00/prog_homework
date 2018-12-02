#include<stdio.h>
#include<stdlib.h>
#define VALUE 9
int a[VALUE];
int small(int count, int num);

int small(int count, int num)
{
    while (count <= VALUE)
    {
        for (int i = 0; i <= VALUE; i++)
        {
            if (num / 10 > 0) {
                if (a[i] / 10 - count == num / 10) {
                    printf("Ближайшее к числу x число: a[%d] = %d\n", i, a[i]);
                    return 0;
                }
            } else if (num / 10 <= 0) {
                if ((a[i] / 10 == 0) || (a[i] / 10 == 1)) {
                    printf("Ближайшее к числу x число: a[%d] = %d\n", i, a[i]);
                    return 0;
                }
            }
        }
        count++; 
    }
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