#include<stdio.h>
#include<stdlib.h>
#ifdef __WIN32 
#include<conio.h> 
#include<windows.h> 
#endif
char button()
{
    char select;
    #if _WIN32
        select = getch();
        printf("WIN\n");
    #else
        system("stty raw");
        select = getchar();
        system("stty cooked");
        printf("UNIX\n");
    #endif
    return select;
}
int main()
{
    char text;
    text = button();
    if (text == 'w') printf("OK!\n");
    return 0;
}