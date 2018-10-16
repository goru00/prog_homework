#include<stdio.h>

int main()
{
    float money = 0.00, get_money, put_money;
    int b = 0;
    int touch;
    printf("1. положить деньги на счет\n2. снять деньги со счета\n3. закрыть счет\n"); 

    while (b != 1)
    {
        printf("\nВведите пункт меню: "); scanf("%d", &touch);
        switch(touch) {
            case 1: 
                printf("Какую сумму денег Вы хотите внести: "); scanf("%f", &put_money);
                money +=put_money;
                printf("\nВы внесли %.2f. Ваш баланс равен %.2f.", put_money, money);
                break;
            case 2:
                printf("\nКакую сумму Вы хотите снять?: "); scanf("%f", &get_money);
                money -=get_money;
                if (money > 0.00)
                    printf("Вы сняли %.2f. На счету осталось %.2f рублей.\n", get_money, money);
                if (money < 0.00)
                    printf("На Вашем счету недостаточно средств, нищеброд. C уважением, Ваш Сбербанк.\n");
                break;
            case 3:
                printf("Счет закрыт.\n");
                b = 1;
                break;
            default:
                printf("Нет такого варианта.\n");
                b = 1;
                break;
        }
    }

    return 0;
}