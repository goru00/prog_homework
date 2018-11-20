#include<stdio.h>
#include<stdlib.h>

#define VALUE_A 9
#define VALUE_B 9

void expmasssiv(int mA[], int mB[], int mC[])
{
	int min, index_j, index_min;
	printf("Массив №1\n");
	for (int i = 0; i <= VALUE_A; i++)
	{
		mA[i] = rand() % 100 + 1;
	}
	for (int i = 0; i <= VALUE_A; i++)
	{
			min = mA[i];
			index_j = i;
			for (int j = i; j <= VALUE_A; j++)
				if (min > mA[j]) 
            	{
                min = mA[j];
                index_min = j;
            	}
        	mA[index_min] = mA[i];
        	mA[i] = min;
	}
	for (int i = 0; i <= VALUE_A; i++)
	{
		printf("a[%d] = %d\n", i, mA[i]);
	}
	printf("\n");
	printf("Массив №2\n");
	for (int i = 0; i <= VALUE_B; i++)
	{
		mB[i] = rand() % 100 + 1;
	}
	for (int i = 0; i <= VALUE_B; i++)
	{
			min = mB[i];
			index_j = i;
			for (int j = i; j <= VALUE_B; j++)
				if (min > mB[j]) 
            	{
                min = mB[j];
                index_min = j;
            	}
        	mB[index_min] = mB[i];
        	mB[i] = min;
	}
	for (int i = 0; i <= VALUE_B; i++)
	{
		printf("a[%d] = %d\n", i, mB[i]);
	}
	int k = VALUE_A + VALUE_B;
	printf("\n");
	printf("Массив №3\n");
	for (int i = 0; i <= VALUE_A + VALUE_B; i++)
	{
		for (int j = 0; i <= VALUE_A; i++)
		{
			mC[j] = mA[j];
		}
		for (int j = VALUE_A + 1, h = 0; j <= k; j++)
		{
			mC[j] = mA[h];
			h++;
		}
	}
	for (int i = 0; i <= VALUE_A + VALUE_B; i++)
	{
			min = mC[i];
			index_j = i;
			for (int j = i; j <= VALUE_B + VALUE_A; j++)
				if (min > mC[j]) 
            	{
                min = mC[j];
                index_min = j;
            	}
        	mC[index_min] = mC[i];
        	mC[i] = min;
	}
	for (int i = 0; i <= VALUE_A + VALUE_B; i++)
	{
		printf("a[%d] = %d\n", i, mC[i]);
	}
}

int main()
{
	int A[VALUE_A], B[VALUE_B];
	int C[VALUE_A + VALUE_B];
	srand(time(NULL));
	expmasssiv(&A[VALUE_A], &B[VALUE_B], &C[VALUE_A + VALUE_B]);

	return 0;
}