/* 19 Вариант */

#include<stdio.h>

int main()
{

int a, b, c;
float d, e, f, W1, W2, W3;

printf("Введите числа\n"); scanf("%d\n%d\n%d\n%f\n%f\n%f", &a, &b, &c, &d, &e, &f);
system("clear"); /* Чистим консоль */
if ((b != 0) && ((c != 0)) && ((d != 0)) && ((e != 0)) && (f != 0)) { /* Если знаменатель != 0, выполняем */
W1 = 3.0 + a/(b*c) + (a*b)/c + d/(e*f) + f/(d*e);
printf("W1=%.4f\n", W1);
}
else printf("Выражение W1 не имеет смысла!\n"); /* иначе выводим ошибку */

W2 = a * c - b - c + b * c;
printf("W2=%.4f\n", W2);

if (b != 0) {
W3 = (d * (a/b)) - (((c/b) * e) + 2.5);
printf("W3=%.4f\n", W3);
}
else printf("Выражение W3 не имеет смысла!\n");

return 0;

}     

