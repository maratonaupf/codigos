/*
 * Leonardo Deliyannis Constantin
 * URI 2416 - Corrida
*/

#include <stdio.h>

int main(){
    int C, N;
    while(scanf("%d %d", &C, &N) != EOF){
        printf("%d\n", C%N);
    }
    return 0;
}
