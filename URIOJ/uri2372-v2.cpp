/*
 * Leonardo Deliyannis Constantin
 * URI 2372 - Reunião
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 112

int N, AG[MAX][MAX];

void floydWarshall(){
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                AG[i][j] = min(AG[i][j], AG[i][k] + AG[k][j]);
}

int main(){
    int M, u, v, w, ans, cur;
    while(scanf("%d %d", &N, &M) != EOF){
        memset(AG, INF, sizeof(AG));
        while(M--){
            scanf("%d %d %d", &u, &v, &w);
            AG[u][v] = AG[v][u] = min(AG[u][v], w);
        }
        floydWarshall();
        ans = INF;
        for(u = 0; u < N; u++){
            cur = 0;
            for(v = 0; v < N; v++)
                if(AG[u][v] != INF)
                    cur = max(cur, AG[u][v]);
            ans = min(ans, cur);
        }
        printf("%d\n", ans);
    }
    return 0;
}
