//commit reset
#include<stdlib.h>
#include<stdio.h>
#define VALUE 9
int main()
{
	int a[VALUE], k, count = 0, end;
	srand(time(NULL));
	for (int i = 0; i <= VALUE; i++)
    {
    	a[i] = (rand() % 100) + 1;
        printf("a[%d] = %d\n", i, a[i]);
    }
	printf("\n");
	end = a[0];
    for (int i = VALUE; i >= 0; i--)
    {
		if (i == 0) {
			printf("a[%d] = %d\n", count, end);
			break;
		} else k = a[i];
		for (int j = 0; j <= VALUE; j++)
		{
			a[j] = k;
			printf("a[%d] = %d\n", count, a[j]);
			break;
		}
		count++;
    }
    return 0;
}