#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 35
char * input(char *text) {
    int str;
    for (int i = 0; i < SIZE; i++) {
        str = rand() % 2;
        if (str == 0) text[i] = ('a' + rand() % ('z' - 'a'));
        else text[i] = ('A' + rand() % ('Z' - 'A'));
        if (i + 2 == SIZE) text[i + 2] = '\0';
    }
}
int change(char *text) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum+=text[i];
        if (text[i] == 'a') text[i] = '?';
    }
    return sum;
}
int main() 
{
    srand(time(NULL));
    char text[SIZE];
    input(text);
    printf("Исходная строка: %s\n", text);
    printf("\nСумма кодов элементов массива: %d\nИзмененная строка: %s\n", change(text), text);
    return 0;
}