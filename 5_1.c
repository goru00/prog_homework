#include<stdio.h>
main()
{
    int n, counter = 0;
    printf("Введите число: ");  scanf("%d", &n);
    system("clear");
    printf("Колличество чисел в числе %d равно: %d\n", n, number(n, counter));
}

int number(int num, int k)
{
    if (num == 0)
        return 1;
    while (num != 0)
    {
        k +=1;
        num = num / 10;
    }
    return k;
}