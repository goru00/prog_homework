#include<stdlib.h>
#include<stdio.h>
#define VALUE 9
int main()
{
	int a[VALUE], k, max, min;
	//srand(time(NULL));
	for (int i = 0; i <= VALUE; i++)
    {
    	a[i] = (rand() % 100) + 1;
        printf("a[%d] = %d\n", i, a[i]);
    }
    k = VALUE;
    for (int i = 0; i <= VALUE; i++)
    {
    	if (a[i] == a[k - 1]) {
    		min = a[i];
    		max = a[k];
    		a[i] = max;
    		a[k] = min;
    		break;
    	}
    	min = a[i];
    	max = a[k];
    	a[i] = max;
    	a[k] = min;
    	k -=1;
    }
    for (int i = 0; i <= VALUE; i++) 
    {
    	printf("\na[%d] = %d\n", i, a[i]);
    }
    return 0;
}