#include<stdio.h>
void easynumb(int x)
{
	int k = 1;
	for (int a = 1; a <= 9; a++)
	{
		if (x % a == 0)
			k -=1;
	}
	if ((x == 3) || ((x == 5)) || (x == 7))
		printf("%3d ", x);
	if (k == 0)
		printf("%3d ", x);
		k = 1;
}

int main()
{
	for (int i = 1; i <= 1000; i++)
	{
		int numb = i;
		easynumb(numb);
	}
	return 0;
}