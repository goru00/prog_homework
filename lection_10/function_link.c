#include<stdio.h>
void f(int &);
void f(int & a)
{
	a++;
}
int main()
{
	int a;
	scanf("%d", &a);
	f(a);
	printf("%d\n", a);
	return 0;
}