#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define SIZE 3
void sort();
void output();
int geommass(int []);
int main()
{
    int result;
    srand(time(NULL));
    int mass[SIZE];
    sort(mass);
    output(mass);
    result = geomvalues(mass);
    printf("Ср.геом: %d\n\n", result);
    if (result < SIZE) {
        printf("Превышает\n");
    } else if (result > SIZE) {
        printf("Не превышает\n");
    }
    return 0;
}
void sort(int *a)
{
    for (int i = 0; i < SIZE; i++)
    {
        *(a + i) = (rand() % 10) + 1;
    }
}
void output(int *a)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\n", a[i]);
    }
    printf("\n");
}
int geomvalues(int a[])
{
    int result;
    float geommass = 1.0;
    for (int i = 0; i < SIZE; i++)
    {
        geommass = geommass * a[i];
    }
    result = pow(geommass, (float) 1.0/SIZE);
    return result;
}