#include <stdio.h>
 
int main (void)
{
    int i, sum = 0, mas[10];
 
    printf ("Введите элементы массива: ");
    for (i = 0; i <= 9; i++)    {
        scanf ("%d", &mas[i]);
        sum += mas[i];
    }
    printf ("Среднее арифметическое элементов: %.2f\n", (float) sum / 10);
    return 0;
}