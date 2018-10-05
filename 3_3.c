#include<stdio.h>

int main()
{
    int x, i=0;

    printf("Какова сторона квадрата?: "); scanf("%d", &x);
    system("clear");
    while (i < x*x)
    {
        if (i % x == 0)
            printf("*\n");
        else printf("*");
        i++;
    }

    return 0;
}