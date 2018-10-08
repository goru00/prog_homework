#include<stdio.h>

int main()
{
	int m = 0, n = 0;
    int x;
    printf("Введите x: "); scanf("%d", &x);
    system("clear");
    m = x % 10;
    n = x % 10;
    if (x < 0) {
        printf("Значение функции равно 0.\n");
    	} 
    	if ((m >= 0 ) && ((n >= 1)) || (m == 0)) {
    	printf("Значение функции равно 1.\n");
    	} 
    	if  ((m >= 1) && (n >= 2)) {
    	printf("Значение функции равно -1.\n");
    }
    
	
	return 0;		
}