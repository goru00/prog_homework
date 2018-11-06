#include<stdio.h>
#include<stdlib.h>
#define VALUE 100
int main()
{
    int a[VALUE];
    printf();
    srand(time(NULL));
    for (int i = 0; i <= VALUE; i++)
    {
        a[i] = (rand() % 100) + 1;
        printf("a[%d] = %d", i, a[i]);
    }
    for ()
    return 0;
}