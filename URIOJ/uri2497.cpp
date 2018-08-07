/*
 * Leonardo Deliyannis Constantin
 * URI 2497 - Contando Ciclos
*/

#include <stdio.h>

int main(){
    int N, T = 0;
    while(scanf("%d", &N), N != -1)
        printf("Experiment %d: %d full cycle(s)\n", ++T, N/2);
    return 0;
}
