/*
 * Leonardo Deliyannis Constantin
 * URI 2831 - Pesos
*/

#include <stdio.h>

int main(){
    int N, i, cur, prev;
    while(scanf("%d", &N) != EOF){
        prev = 0;
        bool ans = true;
        for(i = 1; i <= N; i++){
            scanf("%d", &cur);
            if(cur - prev > 8)
                ans = false;
            prev = cur;
        }
        printf(ans ? "S\n" : "N\n");
    }
    return 0;
}
