/*
 * Leonardo Deliyannis Constantin
 * URI 2355 - Sedex
*/

#include <stdio.h>

int main(){
    int N, A, L, P;
    while(scanf("%d", &N) != EOF){
        scanf("%d %d %d", &A, &L, &P);
        printf("%c\n", (N > A || N > L || N > P) ? 'N' : 'S');
    }
    return 0;
}
