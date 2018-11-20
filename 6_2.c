#include<stdio.h>
#include<stdlib.h>

int simmet(int x, int ar[]);

int simmet(int x, int ar[])
{
    int k = 0;
    for (int i = 0; i <= x; i++)
    {
        printf("%d элемент массива: ", i); scanf("%d", &ar[i]);
    }
    printf("\n");
    for (int i = 0; i <= x; i++)
    {
        if (ar[i] == ar[x - k])
            k++;
        else {
            return printf("Элементы массива не симметричны\n");
        }
    }
    return printf("Элементы массива симметричны\n");

}

int main()
{
    int n;
    printf("Введите число n: "); scanf("%d", &n);
    n--;
    int a[n];
    simmet(n, &a[n]);
    return 0;
}