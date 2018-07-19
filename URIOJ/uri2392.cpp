/*
 * Leonardo Deliyannis Constantin
 * URI 2392 - Pulo do Sapo
*/

#include <stdio.h>
#include <string.h>
#define MAX 112

int main(){
    int N, M, P, D, v[MAX], i;
    while(scanf("%d %d", &N, &M) != EOF){
        memset(v, 0, sizeof v);
        while(M--){
            scanf("%d %d", &P, &D);
            for(i = (P-1)%D; i < N; i += D)
                v[i] = 1;
        }
        for(i = 0; i < N; i++)
            printf("%d\n", v[i]);
    }
    return 0;
}
