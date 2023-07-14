#include<stdio.h>

main(){
    float a,b,result;
    char oper [2];
    printf("Введите первое значение:");
    scanf("%f",&a);
    printf("Введите следующие значение:");
    scanf("%f",&b);
    printf("Введите оператор:");
    scanf("%1s", oper);
    result = (oper[0] == '+') * (a + b) +
             (oper[0] == '-') * (a - b) +
             (oper[0] == '*') * (a * b) +
             (oper[0] == '/') * (a / b);
    printf("%4.2f %s %4.2f = %4.2f\n", a, oper, b, result);
}