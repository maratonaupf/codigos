/*
 * Leonardo Deliyannis Constantin
 * URI 2372 - Reunião
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 112
#define INF 0x3f3f3f3f

void floydWarshall(int N, int AG[MAX][MAX]){
    int i, j, k;
    for(k = 0; k <= N; k++)
        for(i = 0; i <= N; i++)
            for(j = 0; j <= N; j++)
                AG[i][j] = min(AG[i][j], AG[i][k] + AG[k][j]);
}

int main(){
    int N, E, u, v, w;
    int AG[MAX][MAX];
    int cur, ans;
    while(scanf("%d %d", &N, &E) != EOF){
        memset(AG, INF, sizeof AG);
        while(E--){
            scanf("%d %d %d", &u, &v, &w);
            AG[u][v] = AG[v][u] = w;
        }
        floydWarshall(N, AG);
        ans = INF;
        for(u = 0; u < N; u++){
            cur = -INF;
            for(v = 0; v < N; v++)
                if(AG[v][u] != INF)
                    cur = max(cur, AG[v][u]);
            ans = min(ans, cur);
        }
        printf("%d\n", ans);
    }
    return 0;
}
