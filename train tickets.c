#include <stdio.h>
#include <time.h>
#include <locale.h>

int main (){
    int cost_min = 30;
    int cost_middle = 50;
    int cost_max = 100;
    int cost_result = 0;
    int cost_ticket = 0;
    int marshrut = 10;
  
    printf ("Укажите на какой остановке произошла посадка.\n");
    int a;
    scanf ("%d",&a);
  
    printf ("До какой остановки.\n");
    int b;
    scanf ("%d", &b);
    
    int c = b - a;
    if (c <= 3 ) {
        cost_ticket = cost_min;
    } else if (c > 3 && c <= 5) {
        cost_ticket = cost_middle;
    } else if (c > 5 && c <=10) {
        cost_ticket = cost_max;
    }
    
    int d;
    printf ("Укажите количество билетов.\n");
    scanf ("%d", &d);

    cost_result = cost_ticket * d;
    int vmestimost;
    srand(time(NULL));
    vmestimost = rand() %101;
     if (vmestimost == 100) {
        printf ("Билетов нет.\n");
     } else {
         printf ("Итоговая сумма билетов = %d\n", cost_result);
     }
     getch ();
}