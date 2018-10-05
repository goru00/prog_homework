#include<stdio.h>


int main()
{

    int a = 0, b = 1, c = 2;
    system("clear");
    while (c < 99)
    {
        a += 1;
        b += 1;
        c += 1;
        printf("%d\t%d\t%d\n", a, b, c);
        a = c;
        b = c + 1;
        c = c + 2;
    }

    return 0;
}