#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, num, num_quest;
    printf("Отгадайте число от 1 до 100 с 3-ех попыток.\n");
    srand(time(NULL));
    num_quest = rand();
    for (i = 3; i > 0; i--)
    {
    	printf("%d\n", num_quest % 100);
        printf("Введите число: ");
        scanf("%d", &num);
        if (num == (num_quest % 100)) {
            printf("Да, это число %d\n", num_quest % 100);
            return 0;
        }
        else printf("Нет, это не %d. Попробуйте еще раз!(Осталось %d попытки(-а))\n", num, i - 1);
    }
    sleep(1);
    system("clear");
    if (i == 0) printf("3-и попытки кончились. Это было число %d. Пока.\n", num_quest % 100);
    return 0;
}