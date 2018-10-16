#include<stdio.h>

main()
{
    int s, counter = 0;
    printf("Введите символ: ");
    while ((s = getchar()) != EOF)
    {
        switch (s)
        {
            case '0': case '1': case '2': case '3':
            case '4': case '5': case '6': case '7':
            case '8': case '9':
                printf("Цифра: \n");
                counter++;
                break;
            case '\n': case ' ':
                break;
                default:
                printf("Введено некорректное значение \n");
                break;
        }
        printf("Было введено %d цифр \n", counter);
        return 0;
    }
}