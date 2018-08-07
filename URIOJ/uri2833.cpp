/*
 * Leonardo Deliyannis Constantin
 * URI 2833 - Campeonato
*/

#include <stdio.h>
#include <algorithm>
#define MAX 16

int main(){
    int i, x[MAX], k, l;
    char phase[4][10] = { "oitavas", "quartas", "semifinal", "final" };
    while(scanf("%d", x) != EOF){
        k = l = 0;
        for(i = 0; i < MAX; i++){
            if(i) scanf("%d", x+i);
            if(x[i] == 1) k = i;
            if(x[i] == 9) l = i;
        }
        if(k > l) std::swap(k, l);
        for(i = 0; i < 4; i++){
            if(k == l-1 && (l&1)){
                printf("%s\n", phase[i]);
                break;
            }
            k >>= 1;
            l >>= 1;
        }
    }
    return 0;
}
