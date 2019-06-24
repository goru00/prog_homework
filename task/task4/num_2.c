#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 5
int * input(int mass[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            mass[i][j] = rand() % 10 + 1;
        }
    }
    return *mass;
}
void output(int mass[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%3d", mass[i][j]);
        }
        printf("\n");
    }
}
int * create(int a[][SIZE], int b[][SIZE], int c[][SIZE], float d[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            d[i][j] = (float)a[i][j]/((float)b[i][j]+(float)c[i][j])+(float)c[i][j]/(float)a[i][j];
        }
    }
}
int main()
{
    srand(time(NULL));
    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE]; float D[SIZE][SIZE];
    input(A); input(B); input(C);
    printf("\nМассив А: \n");
    output(A); 
    printf("\nМассив B: \n");
    output(B); 
    printf("\nМассив С: \n");
    output(C);
    create(A,B,C,D);
    printf("\nМассив D: \n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%6.3f", D[i][j]);
        }
        printf("\n");
    }
    return 0;
}