#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
int main()
{
	char ch;
	while(!kbhit())
	{
		printf("WAIT\n");
	}
	ch = getch();
	return 0;
}