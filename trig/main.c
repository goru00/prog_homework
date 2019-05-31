#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * Cezar(char *text1, int k)
{
    int i = 0; char text;
    int length = strlen(text1);
    do
    {
        text = text1[i];
        text1[i] = text1[k + i];
        text1[k + i] = text;
        i++;
    } while (text1[i + k] != '\0');
    return text1;
}
int main()
{
    char text1[100];
    int k;
    printf("Введите текст: "); scanf("%s", text1);
    printf("Введите значение сдвига: "); scanf("%d", &k);
    printf("Полученный шифр: %s\n", Cezar(text1, k));
    return 0;
}