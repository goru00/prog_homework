#include<stdio.h>

int main()
{
	int count = 1;
	float p = 4.0, b = 3.0;
	printf("%f\n", p);
	for (int i = 1; i > 0; i ++)
	{
		p = p - 4.0/b + (4.0/b+2.0);
		b +=4.0;
		count +=1;
		if (p == 3.1415) break;
	}
	printf("%d\n", count);
	return 0;
}