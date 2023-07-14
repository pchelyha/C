#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stddef.h>

int* merge(int* z,int* x,int num) {

    int* bigmass=(int*)malloc(sizeof(int)*num*2);
    for (int j = 0; j < num; j++)bigmass[j] = z[j];
    for (int j = num; j < ( num*2 ); j++)bigmass[j] = x[j-num];
    return bigmass;
}
int main() {
    int n;
    // srand(time(NULL));
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)a[i] = rand() % 50;
    int* a1 = (int*)malloc(sizeof(int)* n);
    for (int i = 0; i < n; i++)a1[i] = rand() % 50;
    int* p = merge(a,a1,n);//bigmass

    for (int i = 0; i < (2 * n); i++) {
        printf("%d ", p[i]);
    }
    getch();
}