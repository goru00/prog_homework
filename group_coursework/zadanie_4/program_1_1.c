#include<stdio.h>
#include <math.h>
double fact(int i)   
{
	if(i == 0) return 1;	
    if(i < 0) {
    	return 0;
    } else return i * fact(i - 1);		
}
int dec(double E, double *row)
{
    int i = 0;
    do
	{
		*row+=1/fact(i);			
		i++;
	}
	while(M_E-*row>E);	
    return i;
}
int dr(double E, int i, double *inf)
{
    int k=1, l=1; double sum = 0;
    do
	{
		for (int k = l; k >= 1; k--)
		{
			if ((k % 2) == 0)
			{
				sum = 1 / (2 + sum);
			}
			else
			{
				sum = 1 / (k - sum);
			}
		}
		if (fabs(M_E - (sum + 1))<E)
		{
			break;
		}
		l++;
	} 
	while (l < i + 10);
    *inf=1+sum;	
    return l;
}
int main() 
{
	int i, l; double row=0, E; 				
	printf("Введите точность вычисления: "); scanf("%lf", &E);			
    i = dec(E, &row);	
    printf("Значение числового ряда: %10.10lf; Кол-во членов ряда: %d\n", row, i);
    double inf;	
    l = dr(E,i, &inf);				
    printf("Значение цепной дроби: %10.10lf; Кол-во членов дроби: %d \n", inf, l);
	return 0;
}