/*
 * Leonardo Deliyannis Constantin
 * URI 2763 - Entrada e Saída de CPF
*/

#include <stdio.h>
#define MAX 21

int main(){
    int a, b, c, d;
    while(scanf("%d.%d.%d-%d", &a, &b, &c, &d) != EOF){
        printf("%03d\n%03d\n%03d\n%02d\n", a, b, c, d);
    }
    return 0;
}
