#include<stdio.h>
#include<stdlib.h>
#ifdef __WIN32 
#include<conio.h> 
#include<windows.h> 
#endif
void button()
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
    if (select == 'w') printf("OK!\n");
}
int main()
{
    button();
    return 0;
}