#include<stdio.h>

int main()
{
    float money = 0.00, get_money, put_money;
    int touch;
    printf("1. положить деньги на счет\n2. снять деньги со счета\n3. закрыть счет\nВведите номер действия: "); scanf("%d", &touch);

    switch(touch) {
        case 1: 
            printf("Какую сумму денег Вы хотите внести: "); scanf("%f", &put_money);
            printf("\nВы внесли %.2f. Ваш баланс равен %.2f.", put_money, money+put_money);
            break;
        case 2:
            printf("\nКакую сумму Вы хотите снять?: "); scanf("%f", &get_money);
            if (money > 0.00) {
                printf("Вы сняли %.2f. На счету осталось %.2f рублей.\n", get_money, money-get_money);
            } else printf("На Вашем счету недостаточно средств, нищеброд. C уважением, Ваш Сбербанк.\n");
            break;
        case 3:
            printf("Счет закрыт.\n");
            break;
        default:
            printf("Нет такого варианта.\n");
            break;
    }

    return 0;
}