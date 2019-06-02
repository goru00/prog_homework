#include<stdio.h>
#include<stdlib.h>
#ifdef _WIN32
    #include<conio.h>
    #include<windows.h>
#endif

void khbit(char *select)
{
    #ifdef _WIN32
        select = getch();
    #elif _unix_
        system("stty raw");
        select = getchar();
        system("stty cooked");
    #endif
}
int main()
{
    char *select;
    khbit(select);
    if (select == 56) printf("OK!\n");
    return 0;
}