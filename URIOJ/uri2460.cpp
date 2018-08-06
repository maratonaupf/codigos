/*
 * Leonardo Deliyannis Constantin
 * URI 2460 - Fila
*/

#include <stdio.h>
#include <string.h>
#define MAX 102345

int main(){
    int N, M, x, i, f[MAX];
    bool in[MAX];
    while(scanf("%d", &N) != EOF){
        memset(in, 0, sizeof in);
        for(i = 0; i < N; i++){
            scanf("%d", f+i);
            in[f[i]] = true;
        }
        scanf("%d", &M);
        while(M--){
            scanf("%d", &x);
            in[x] = false;
        }
        bool first = true;
        for(i = 0; i < N; i++){
            if(in[f[i]]){
                if(first) first = false;
                else printf(" ");
                printf("%d", f[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
