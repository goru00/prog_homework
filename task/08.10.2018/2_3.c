#include<stdio.h>

int main()
{

    float x1,x2,x3,x4,x5;
    int max = 32768, min = -32768;
    printf("Введите 5 чисел: \n"); 
    scanf("%f\n%f\n%f\n%f\n%f", &x1, &x2, &x3, &x4, &x5);
    system("clear");

    if (x1 < max) {
        max = x1;
        if (x2 > max) {
            max = x2;
            min = x1;
        }
        if (x3 > max) { 
            max = x3;
            min = x2;
        }
        if (x4 > max) {
            max = x4;
            min = x3;
        }
    } else if (x2 < max) {
        max = x2;
        if (x3 > max) {
            max = x3;
            min = x2;
        }
        if (x4 > max) { 
            max = x4;
            min = x3;
        }
    } else if (x3 < max) {
        max = x3;
        if (x4 > max) {
            max = x4;
            min = x3;
        }
    }
    printf("Сумма равна: %d\n", min+max);

    return 0;
}

