#include<stdio.h>
#include<math.h>
main()
{
    int x;
    printf("Введите число: ");  scanf("%d", &x);
    system("clear");
    koren(x);
    return 0;
}
void koren(double n)
{
    int num;
    n = sqrt(n);
    if (n == (int) n)
        printf("Число %d является квадратом числа %d", (int) n * n, n);
    else printf("Число %d является квадратом числа %d", n * n, n);

}