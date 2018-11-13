#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[] = {2, -7, 4, 5, 7, -2, 8, -15, 9, 1}; //массив чисел.
	int k_pol = 0, k_otr = 0, i = 0, j = 0;
	for (int i = 0; i <= 9; i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
		if (a[i] < 0) //считаем кол-во отрицательных чисел//
			k_otr+=1;
		if (a[i] > 0) //считаем кол-во положительных чисел
			k_pol+=1;
	}
	int sum_elem = (k_otr + k_pol) - 1;
	int pol[k_pol]; //массив с пол.числами
	int otr[k_otr]; //массив с отр.числами
	i = 0;
	printf("\n\n");
	while (j != k_otr) // вводим отр.числа в отдельный массив otr[]
	{
		if (a[i] < 0) {
			otr[j] = a[i];
			j++;
		}
		i++;
	}
	j = 0;
	i = 0;
	while (j != k_pol) //вводим положительные числа в отдельный массив pol[]
	{
		if (a[i] > 0) {
			pol[j] = a[i];
			j++;
		}
		i++;
	}
	for (int i = 0, max = 0; i < k_pol; i++) //вводим положительные числа из pol[] > a[] 
	{
		a[i] = pol[max];
        max++; // числа массива в диапазоне max=0
        printf("a[%d] = %d\n", i, a[i]);
	}
    for (int i = k_pol, min = 0; i <= 9; i++) //вводим отрицательные числа из otr[] > a[]
	{
		a[i] = otr[min];
        min++; // числа массива в диапазоне min=0
        printf("a[%d] = %d\n", i, a[i]);
	}
	return 0;
}
