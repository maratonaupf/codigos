/*
 * Leonardo Deliyannis Constantin
 * URI 2227 - Aeroporto
*/

#include <stdio.h>
#include <string.h>
#define MAX 112

int main(){
    int A, V, i, x, y, T = 0, ans;
    int flow[MAX];
    while(scanf("%d %d", &A, &V), A){
        memset(flow, 0, sizeof flow);
        ans = 0;
        for(i = 0; i < V; i++){
            scanf("%d %d", &x, &y);
            if(++flow[x] > ans) ans = flow[x];
            if(++flow[y] > ans) ans = flow[y];
        }
        printf("Teste %d\n", ++T);
        for(x = 1; x <= A; x++){
            if(flow[x] == ans){
                printf("%d ", x);
            }
        }
        printf("\n\n");
    }
    return 0;
}
