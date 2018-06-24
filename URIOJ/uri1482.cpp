/*
 * Leonardo Deliyannis Constantin
 * URI 1482 - Noite no Museu
*/ 

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 20

int N, t[MAX], dist[MAX][MAX];
char memo[MAX][1 << MAX];

int tsp(int cur, int mask, int remTime){
    if(remTime < 0)
        return -1;
    if(remTime == 0)
        return 0;
    if(memo[cur][mask] != -1)
        return memo[cur][mask];
    int ans = 0;
    for(int u = 0; u < N; u++){
        int cost = dist[cur][u] + t[u];
        if(!(mask & (1 << u)))
            ans = max(ans, 1 + tsp(u, mask | (1 << u), remTime - cost));
    }
    return memo[cur][mask] = ans;
}

int main(){
    int u, v;
    while(scanf("%d", &N), N != 0){
        for(u = 0; u < N; u++)
            scanf("%d", &t[u]);
        for(u = 0; u < N; u++)
            for(v = 0; v < N; v++)
                scanf("%d", &dist[u][v]);
        memset(memo, -1, sizeof(memo));
        int ans = 0;
        for(u = 0; u < N; u++)
            ans = max(ans, 1 + tsp(u, (1<<u), 420-t[u]));
        printf("%d\n", ans);
    }
    return 0;
}
