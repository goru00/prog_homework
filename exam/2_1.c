#include<stdio.h>
#include<stdlib.h>
int main()
{
    int point[8], k;
    float rh, sh;
    printf("Введите точку ax: "); scanf("%d", &point[0]);
    printf("Введите точку ay: "); scanf("%d", &point[1]);
    printf("Введите точку bx: "); scanf("%d", &point[2]);
    printf("Введите точку by: "); scanf("%d", &point[3]);
    printf("Введите точку cx: "); scanf("%d", &point[4]);
    printf("Введите точку cy: "); scanf("%d", &point[5]);
    printf("Введите точку dx: "); scanf("%d", &point[6]);
    printf("Введите точку dy: "); scanf("%d", &point[7]);
    k = (point[2]-point[0])*(point[7]-point[5])-(point[3] - point[1])*(point[6]-point[4]);
    rh = (point[1] - point[5])*(point[6] - point[4])-(point[0] - point[4])*(point[7]-point[5]);
    sh = (point[1] - point[5])*(point[2] - point[0])-(point[0] - point[4])*(point[3]-point[1]);
    if ((rh / k >= 0) && (rh <= 1) && (sh / k >= 0) && (sh / k <= 1)) printf("Имеют.\n");
    else printf("Не имеют.\n");
    return 0;
}