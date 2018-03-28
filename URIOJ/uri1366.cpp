/*
 * Leonardo Deliyannis Constantin
 * URI 1366 - Jogo de Varetas
*/

#include <stdio.h>

int main(){
    int N, i, v;
    int ans, remain;
    while(scanf("%d", &N), N != 0){
        ans = remain = 0;
        for(i = 0; i < N; i++){
            scanf("%*d %d", &v);
            ans += v/4;
            v -= (v/4) * 4;
            remain += v/2;
        }
        ans += remain/2;
        printf("%d\n", ans);
    }
    return 0;
}
