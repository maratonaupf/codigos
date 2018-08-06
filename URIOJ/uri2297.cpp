/*
 * Leonardo Deliyannis Constantin
 * URI 2297 - Bafo
*/

#include <stdio.h>

int main(){
    int N, A, B, a, b, T = 0;
    while(scanf("%d", &N), N != 0){
        A = B = 0;
        while(N--){
            scanf("%d %d", &a, &b);
            A += a;
            B += b;
        }
        printf("Teste %d\n", ++T);
        printf("%s\n\n", A > B ? "Aldo" : "Beto");
    }
    return 0;
}
