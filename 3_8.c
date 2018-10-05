#include<stdio.h>

int main() 
{
    unsigned long long int i = 1;
    while (1)
    {
        i = i * 2;
        printf("%lld\n", i);
    }

    return 0;
}