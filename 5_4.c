#include<stdio.h>
void fibonachi(Fi)
{
    int F1 = 1, F2 = 1,k,Finum,Finew,Fipos;
	printf("F(1) = %d\nF(2) = %d\n", F1, F2);
	if (Fi > 2)
	{
		Finum = F1 + F2;
		printf("F(3) = %d\n", Finum);
		Fipos = F2;
		for (k = 4; k <= Fi; k++)
		{
			Finew = Fipos + Finum;
			printf("F(%d) = %d\n", k, Finew);
			Fipos = Finum; 
			Finum = Finew;
		}
		return 0;
    }
}

main()
{
    int n;
    printf("Введите целое число N: ");  scanf("%d", &n);
    while (n <= 1)
	{
		printf("Введите число N: ");
		scanf("%d", &n);
		if (n > 1)
		break;
	}
    system("clear");
    fibonachi(n);
    return 0;
}