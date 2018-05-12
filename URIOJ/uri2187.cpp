/*
 * Leonardo Deliyannis Constantin
 * URI 2187 - Bits Trocados
*/

#include <stdio.h>

int main(){
    int V, n50, n10, n5, n1, tc = 0;
    while(scanf("%d", &V), V != 0){
        n50 = V / 50;
        V %= 50;
        n10 = V / 10;
        V %= 10;
        n5 = V / 5;
        V %= 5;
        n1 = V;
        V %= 1;
        printf("Teste %d\n", ++tc);
        printf("%d %d %d %d\n\n", n50, n10, n5, n1);
    }
    return 0;
}
