#include<stdio.h>

main() 
{
    int x1,x2,x3;
    printf("Введите стороны прямоугольника: ");
    scanf("%d%d%d", &x1,&x2,&x3);
    system("clear");
    if ((x1 == 0) && ((x2 == 0)) && (x3 == 0)) {
        if ((x1 == x2) && ((x1 != x3)) && (x2 != x3)) {
            printf("Могут\n");
        } else if ((x1 == x3) && ((x1 != x2)) && (x3 != x2)) { 
            printf("Могут\n");
        } else if ((x2 == x3) && ((x2 != x1)) && (x3 != x1)) {
            printf("Могут\n");
        } else printf("Не могут\n");
    } else printf("Стороны не могут равняться 0!\n");
    return 0;
}