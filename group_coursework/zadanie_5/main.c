#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
long long umn();
long long del();
long long slosh();
long long vichit();
long long step();
long long umn()
{
    int a=rand()%21,b=rand()%21;
    long long g=a*b;
    printf("%d*%d=",a,b);
    return g;
}
long long del()
{
    int b=rand()%20+1;
    int a=rand()%12*b;
    long long g=a/b;
    printf("%d/%d=",a,b);
    return g;
}
long long slosh()
{
    int a=rand()%100,b=rand()%100;
    long long g=a+b;
    printf("%d+%d=",a,b);
    return g;
}
long long vichit()
{
    int a=rand()%100,b=rand()%100;
    long long g=a-b;
    printf("%d-%d=",a,b);
    return g;
}
long long step()
{
    int a=rand()%20,b=rand()%5;
    long long g=pow(a,(b%5));
    printf("%d^%d=",a,(b%5));
    return g;
}
int main()
{
	int point=0;
	long long f,z;
    srand ( time(NULL) );
    do{
    int x=rand()%5;
    switch ( x )
    {
        case 1:
        f=umn();
        break;
        case 2:
        f=del();
        break;
        case 4:
        f=slosh();
        break;
        case 3:
        f=vichit();
        break;
        case 0:
        f=step();
        break;
    }
printf("\nВведите ответ:");
z=999;
scanf("%lli",&z);if(z==999) break; else
if(f==z) {point+=100;
	printf("Ответ верен!\n"); } 
else {point-=100;
printf("Ответ не верен!Ответ:%lli\n",f);}
    }while (z!=999);
   printf("Final points %d",point);
    return 0;
}

