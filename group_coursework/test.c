#include<stdio.h>
#include<stdlib.h>
#ifdef _WIN32
    #include<conio.h>
    #include<windows.h>
#endif

void button()
{
    char select;
    #ifdef _WIN32
        select = getch();
    #else
        system("stty raw");
        select = getchar();
        system("stty cooked");
    #endif
    if (select == 56) printf("OK!\n");
}
int main()
{
    button();
    return 0;
}