/*
 * Leonardo Deliyannis Constantin
 * URI 2761 - Entrada e Saída de Vários Tipos
*/

#include <stdio.h>
#define MAX 52

int main(){
    int a;
    float b;
    char c, d[MAX];
    while(scanf("%d %f %c %[^\n]s", &a, &b, &c, d) != EOF){
        printf("%d%f%c%s\n", a, b, c, d);
        printf("%d\t%f\t%c\t%s\n", a, b, c, d);
        printf("%10d%10f%10c%10s\n", a, b, c, d);
    }
    return 0;
}
