/*
 * Leonardo Deliyannis Constantin
 * URI 1136 - Bingo!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 112

int main(){
    int N, B, i, j, v[MAX];
    bool call[MAX], ans;
    while(scanf("%d %d", &N, &B), N){
        memset(call, 0, sizeof call);
        for(i = 0; i < B; i++){
            scanf("%d", v+i);
            for(j = 0; j < i; j++){
                call[abs(v[i]-v[j])] = 1;
            }
        }
        ans = true;
        for(i = 1; i <= N && ans; i++)
            if(!call[i])
                ans = false;
        printf("%c\n", ans ? 'Y' : 'N');
    }
    return 0;
}
