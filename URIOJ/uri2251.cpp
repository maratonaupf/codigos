/*
 * Leonardo Deliyannis Constantin
 * URI 2251 - Torres de Hanói
*/

#include <stdio.h>

int main(){
    int N, T = 0;
    while(scanf("%d", &N), N){
        printf("Teste %d\n", ++T);
        printf("%d\n\n", (1 << N) - 1);
    }
    return 0;
}
