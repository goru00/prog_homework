#include<stdio.h>

#define VALUE_A 9
#define VALUE_B 9

int main()
{
	int min, index_j;
	int A[VALUE_A], B[VALUE_B];
	int C[VALUE_A + VALUE_B];
	srand(time(NULL));
	printf("Массив №1\n");
	for (int i = 0; i <= VALUE_A; i++)
	{
		A[i] = rand() % 100 + 1;
	}
	for (int i = 0; i <= VALUE_A; i++)
	{
			min = A[i];
			index_j = i;
			for (int j = i; j <= VALUE_A; j++)
				if (min > A[j]) 
            	{
                min = A[j];
                index_min = j;
            	}
        	A[index_min] = A[i];
        	A[i] = min;
	}
	printf("\n");
	printf("Массив №2\n");
	for (int i = 0; i <= VALUE_B; i++)
	{
		B[i] = rand() % 100 + 1;
		printf("B[%d] = %d\n", i, B[i]);
		if (i >= 1) {

		}
	}
}