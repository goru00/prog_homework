#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double summary(double num1, double num2);
void paral();

void paral()
{
    int k, b;
    srand(time(NULL));
    k = (rand() % 10) + 1;
    b = (rand() % 10) + 1;
    printf("Первая функция y=%dx+%d\n", k, b);
    int x1,x2,ord1,ord2;
    int y1,y2;
    printf("Введите значения x1 и x2 для первой прямой: "); scanf("%d %d", &x1, &x2);
    y1 = k * x1 + b;
    y2 = k * x2 + b;
    ord1 = (y2 - y1) / (x2 - x1);
    printf("Угловой коэффициент первой прямой: %d\n", ord1);
    k = (rand() % 10) + 1;
    b = (rand() % 10) + 1;
    printf("Вторая функция y=%dx+%d\n", k, b);
    printf("Введите значения x1 и x2 для второй прямой: "); scanf("%d %d", &x1, &x2);
    y1 = k * x1 + b;
    y2 = k * x2 + b;
    ord2 = (y2 - y1) / (x2 - x1);
    printf("Угловой коэффициент второй прямой: %d\n", ord2);
    if (ord1 == ord2)
        printf("Прямые параллельны\n");
    else printf("Прямые не параллельны\n");
}

double summary(double num1, double num2)
{
    double sum = 0;
    int k = 1;
    while(num1--)
    {
        sum += (1/pow(2, k)) * ((sin(num2)) / pow(num2, k+1));
        ++k;
    } 
    return sum;
}
int main()
{
    int select;
    printf("Какой номер Вы хотите рассмотреть первым? "); scanf("%d", &select);
    switch(select)
    {
        case 1: 
        {
            /* Задание №1 */
            printf("Задание №1\n\n");
            int a, b;
            float rad, c;
            printf("Введите a и b: "); scanf("%d %d", &a, &b);
            printf("\n");
            printf("Введите угол в радианах: "); scanf("%f", &rad);
            printf("\n");
            while ((a <= 0) || ((b <= 0)) || (rad <=0))
            {
                printf("Введите a и b: "); scanf("%d %d", &a, &b);
                printf("\n");
                printf("Введите угол в радианах: "); scanf("%f", &rad);
                printf("\n");
                system("clear");
            }
            c = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(rad)); 
            printf("Третья сторона равна: %.0f\n", c);

            return 0;
        }
        case 2:
        {
            /* Задание №2 */
            printf("Задание №2\n\n");
            paral();
            return 0;
        }
        case 3:
        {
            /* Задание №3 */
            printf("Задание №3\n\n");
            int n,x;
            printf("Введите число n: "); scanf("%d", &n);
            printf("\nВведите число x: "); scanf("%d", &x);
            printf("Результат: %f\n: ", summary(n, x));

            return 0;
        }
    }
    return 0;
}

