/*
 * Leonardo Deliyannis Constantin
 * URI 2598 - Colocando Radares
*/

#include <stdio.h>

int main(){
    int C, N, M;
    scanf("%d", &C);
    while(C--){
        scanf("%d %d", &N, &M);
        printf("%d\n", N/M + ((N%M != 0) ? 1 : 0));
    }
    return 0;
}
