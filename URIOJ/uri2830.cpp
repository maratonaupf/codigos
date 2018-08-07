/*
 * Leonardo Deliyannis Constantin
 * URI 2830 - Copa
*/

#include <stdio.h>
#include <algorithm>

int main(){
    int k, l, i;
    char phase[4][11] = { "oitavas", "quartas", "semifinal", "final" };
    while(scanf("%d %d", &k, &l) != EOF){
        if(k > l) std::swap(k, l);
        k--, l--;
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
