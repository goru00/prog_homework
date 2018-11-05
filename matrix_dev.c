#include<stdio.h>


int matrix_triangle(int m, int n)
{
    int a[m][n], matrix_triangle_view;
    printf("\n");
    for (int m = 0; m < 3; m++)
    {
        for (int n = 0; n < 3; n++)
        {
            printf("m = %d, n = %d = ", m + 1, n + 1);
            scanf("%d", &a[m][n]);
        }
    }
    printf("\n\n");
    for (int m = 0; m < 3; m++)
    {
        for (int n = 0; n < 3; n++)
        {
            printf("%6d", a[m][n]);
        }
        printf("\n\n");
    }
    printf("\n\nDeterminant = (a11 * a22 * a33) + (a31 * a12 * a23) + (a21 * a13 * a32) - (a31 * a22 * a13) - (a21 * a12 * a33) - (a11 * a23 * a32)\n");
    return matrix_triangle_view = a[0][0] * a[1][1] * a[2][2] + a[2][0] * a[0][1] * a[1][2] + a[1][0] * a[0][2] * a[2][1] - a[2][0] * a[1][1] * a[0][2] - a[1][0] * a[0][1] * a[2][2] - a[0][0] * a[1][2] * a[2][1];
} 

int main()
{
    int matrix_value_m, matrix_value_n;
    system("clear");
    printf("Matrix calculator:\n\nPlease input dimension matrix(example: 3 3 or 3 5): ");
    scanf("%d%d", &matrix_value_m, &matrix_value_n);
    if ((matrix_value_m == 3) && (matrix_value_n == 3))
        printf("Matrix Triangle Determinated == %3d\n\n",matrix_triangle(matrix_value_m, matrix_value_n));
    
    return 0;
}