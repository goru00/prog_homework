#include<stdio.h>
int invers(int invers);
int sub(int sub);

int sub(int x, int number)
{
    int k = 0;
    printf("%d\n", number);
    while (number > 0)
    {
        if (x > number) {
            number = x - number;
            k +=1;
            x = number;
        }
        if (number > x) {
            number = number - x;
            k +=1;
            x = number;
        }
        invers(number);
    }
    printf("Ноль найден. Количество попыток: %d\n", k);
}

int invers(int a, int num)
{
    while (a != 0)
    {
        num = (num * 10) + (a % 10);
        a /= 10;
    }
    sub(a, num);
    //printf("%d\n", num);
}

int main()
{int n;
    printf("Введите n: ");  scanf("%d", &n);
    system("clear");
    invers(n);
}