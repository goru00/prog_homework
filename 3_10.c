#include<stdio.h>

int main()
{
    int fctr = 0, i, n;
    printf("Введите число n: "); scanf("%d", &n);
    system("clear");
    i = n - 1;
    if (n == 1) {
        printf("Значение факториала равно: %d\n", n);
        return 0;
    }
    while (i != 0)
    {
     	if (n - 1 == i) {
     		fctr = n * (n-i);
     		i = i - 1;
     	} else {
     		fctr = fctr * (n - i);
     		i = i - 1;
     	}
    }
    printf("Значение факториала равно: %d\n", fctr);
    return 0;	
}