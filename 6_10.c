#include<stdio.h>
#include<math.h>
#define VALUE 9
int a[];

float f(float x);

float delpol(float a[VALUE]);

float f(float x)
{
    return sqrt(x);
}
float delpol(float a[VALUE])
{
    float x = 0, x2, x1;
    for (int i = 0; i < VALUE; i++)
    {
        x +=(a[i] + a[i + 1]);
    }
    x /=2;
    while (abs(f(x)) > 0.001)
    {
        if (f(x) > 0)
            x2 = x;
        else 
            x1 = x;
        x = (x1 + x2) / 2;
    }
}
int main()
{
    srand(time(NULL));
    for (int i = 0; i <= VALUE; i++)
    {
        a[i] = (rand() % 100) + 1;
    }
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
    delpol();
    return 0;
}