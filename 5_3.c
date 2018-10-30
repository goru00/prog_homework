#include<stdio.h>

int doublefact(int fact)
{
    int i;
    if (fact % 2 == 0) {
        for (i = fact - 2; i >= 1; i = i - 2)
        {
            fact = fact * i;
        }
    }
    if (fact % 2 == 1) {
        for (i = fact - 2; i >= 2; i = i - 2)
        {
            fact = fact * i;
        }
    }
    if (fact == 0)
        fact = 1;

    return fact;
}

int main()
{
    int n;
    printf("Введите число: ");  scanf("%d", &n);
    while (n < 0)
	{
		printf("Введите число: ");
		scanf("%d", &n);
		if (n >= 0)
		break;
	}
    system("clear");
    printf("Значение двойного факториала числа %d равно: %d\n", n, doublefact(n));

    return 0;
}
