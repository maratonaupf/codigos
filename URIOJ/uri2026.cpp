/*
 * Leonardo Deliyannis Constantin
 * URI 2026 - Árvore de Natal
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std; 
#define MAXP 112
#define MAXW 1123

int P, W;
int memo[MAXP][MAXW];
int e[MAXP], pc[MAXP];

int dp(int id, int w){
    if(id == P || w == 0) return 0;
    if(memo[id][w] != -1) return memo[id][w];
    if(pc[id] > w) return memo[id][w] = dp(id+1, w);
    return memo[id][w] = max(dp(id+1, w), e[id] + dp(id+1, w - pc[id]));
}

int main(){
    int G;
    scanf("%d", &G);
    for(int g = 1; g <= G; g++){
        scanf("%d %d", &P, &W);
        for(int i = 0; i < P; i++){
            scanf("%d %d", &e[i], &pc[i]); 
        }
        memset(memo, -1, sizeof(memo));
        printf("Galho %d:\n", g);
        printf("Numero total de enfeites: %d\n\n", dp(0, W));
    }
    return 0;
}
