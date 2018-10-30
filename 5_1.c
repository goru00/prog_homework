#include<stdio.h>

main()
{
    int n, counter = 0;
    printf("Введите число: ");  scanf("%d", &n);
    system("clear");
    printf("Колличество чисел в числе %d равно: %d\n", n, number(n, counter));

    return 0;
}

int number(int num, int k)
{
    while (num != 0)
    {
        if (num % 10 >= 0) {
            k +=1;
        }
        num = num / 10;
    }
    return k;
}