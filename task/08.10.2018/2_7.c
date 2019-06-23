int main()
{

    float x1,x2,x3,x4,y1,y2,y3,y4;
    printf("Введите координаты оси OX: "); scanf("%f%f%f%f", &x1, &x2, &x3, &x4);
    printf("Введите координаты оси OY: "); scanf("%f%f%f%f", &y1, &y2, &y3, &y4);
    system("clear");

    if (x1 == x2) x4 = x3;
    if (x1 == x3) x4 = x2;
    if (x2 == x3) x4 = x1;
    if (y1 == y2) y4 = y3;
    if (y1 == y3) y4 = y2;
    if (y2 == y3) y4 = y1;

    printf("Координаты 4 вершины: (%.3f ; %.3f)\n", x4, y4);

    return 0;

}

