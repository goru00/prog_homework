#include<stdio.h>

int main()
{
	int i, krat, sum = 0;
	system("reboot");
	for (i = 2; i <=30; i++)
	{
		krat = i;
		if (krat % 2 == 0)
		     sum = sum + krat;
	}
	printf("Сумма чисел кратных 2 равна: %d\n", sum);
	return 0;
}