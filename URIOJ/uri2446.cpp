/*
 * Leonardo Deliyannis Constantin
 * URI 2446 - Troco
*/

#include <stdio.h>
#define MAXM 1123

int V, M;
int c[MAXM];

int solve(int v, int m){
    if(v < 0) return false;
    if(v == 0) return true;
    if(m == 0) return false;
    return solve(v-c[m], m-1) || solve(v, m-1);
}

int main(){
    int V, M, i;
    while(scanf("%d %d", &V, &M) != EOF){
        for(i = 1; i <= M; i++){
            scanf("%d", c+i);
        }
        printf("%c\n", solve(V, M) ? 'S' : 'N');
    }
    return 0;
}
