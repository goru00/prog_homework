#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * Cezar(char *text1, char *text2, int k)
{
    int i = 0, flag = k, j = 0;
    int length = strlen(text1);
    do
    {
        
    } while (text1[i] != '\0');
    return text2;
}
int main()
{
    char text1[100], text2[100];
    int k;
    printf("Введите текст: "); scanf("%s", text1);
    printf("Введите значение сдвига: "); scanf("%d", &k);
    printf("Полученный шифр: %s\n", Cezar(text1, text2, k));
    return 0;
}