/*
 * Leonardo Deliyannis Constantin
 * URI 1573 - Fábrica de Chocolate
*/

#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c), a != 0){
        printf("%d\n", (int)cbrt(a * b * c));
    }
    return 0;
}
