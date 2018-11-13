#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, k = 0;
    printf("Введите число n: "); scanf("%d", &n);
    int a[n];
    for (int i = 0; i <= n; i++)
    {
        printf("%d элемент массива: ", i + 1); scanf("%d", &a[i]);
    }
    printf("\n");
    for (int i = 0; i <= n; i++)
    {
        if (a[i] == a[n - k])
            k++;
        else {
            printf("Элементы массива не симметричны.\n");
            return 0;
        }
    }
    printf("Элементы массива симметричны.\n");
    
    return 0;
}