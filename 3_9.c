#include<stdio.h>

main() 
{
    int x1,x2,x3;
    printf("Введите стороны прямоугольника: ");
    scanf("%d%d%d", &x1,&x2,&x3);
    system("clear");
    if ((x1 == x2) && ((x1 != x3)) && (x2 != x3)) {
        printf("Могут\n");
    } else if ((x1 == x3) && ((x1 != x2)) && (x3 != x2)) { 
        printf("Могут\n");
    } else if ((x2 == x3) && ((x2 != x1)) && (x3 != x1)) {
        printf("Могут\n");
    } else printf("Не могут\n");

    return 0;
}