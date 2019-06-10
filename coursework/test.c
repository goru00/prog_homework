#include <iostream>
#include <math.h>
using namespace std;
double fact(int i)   
{
	if(i == 0)
	{
		return 1;	
	}
    if(i < 0)
    {
    	return 0;
    }
    else
    return i * fact(i - 1);		//функция для вычисления факториала
}
int main() 
{
	int i=0, k=1, l=1;
	double row=0, E; 				//начальные переменные
		scanf("%lf", &E);			//ввод погрешности
	do
	{
		row+=1/fact(i);				//вычисление ряда
		i++;
	}
	while(M_E-row>E);			//условие, при котором цикл останавливается
    	printf("row=%10.10lf, i=%d \n", row, i);
    double sum3=0, inf;			//переменные для вычисления цепной дроби
    do
	{
		for (int k = l; k >= 1; k--)
		{
			if ((k % 2) == 0)
			{
				sum3 = 1 / (2 + sum3);
			}
			else
			{
				sum3 = 1 / (k - sum3);
			}
		}
		if (fabs(M_E - (sum3 + 1))<E)
		{
			break;
		}
		l++;
	} 
	while (l < i + 10);
    inf=1+sum3;						//в начале цепной дроби присутсвует единица, которая выбивается из цикла.
    	printf("inf=%10.10lf, l=%d \n", inf, l);
    if(l<i)
    {
    	printf("С заданной погрешностью E=%5.10lf, бесконечная дробь, с количеством итераций l=%d быстрее сходится к числу е, чем ряд, c количевством итераиций i=%d.\n", E, l, i);
    }
    else
    {
    	printf("С заданной погрешностью E=%5.10lf, ряд, с количеством итераций i=%d быстрее сходится к числу е, чем бесконечная дробь, c количевством итераиций l=%d.\n", E, i, l);
    }
	return 0;
}