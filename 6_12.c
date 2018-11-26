#include<stdio.h>
int n;
int a[]; 

int erats(int count);
void sort();

void sort()
{
    int min, index_min;
    for (int i = 0; i < n; i++)
    {
        min = a[i];
        index_min = i;
        for (int j = i; j <= n; j++)
            if (min > a[j]) 
            {
                min = a[j];
                index_min = j;
            }
        a[index_min] = a[i];
        a[i] = min;
    }
}
int erats(int count)
{
    int truenum;
    for (int i = 0; i <= n; i++)
    {
        a[i] = count + i;
    }
    while (count <= n)
    {
        for (int i = 0; i <= n; i++)
        {
            truenum = 0;
            for (int j = count + 1; j <= n; j++)
            {
                if ((a[i] % count == 0) && (a[i] % j != 0))
                    truenum++;
            }
            if (truenum > 0)
                a[i] = count;
        }
        count++;
    }
    sort();
    for (int i = 0, count = 0; i <= n; i++)
    {
        if (a[i] != a[i + 1]) {
            printf("a[%d] = %d\n", count, a[i]);
            count++;
        }
    }
    return 0;
}
int main()
{
    int k = 2;
    printf("Введите число n: "); scanf("%d", &n);
    erats(k);
}