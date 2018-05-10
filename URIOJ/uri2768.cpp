/*
 * Leonardo Deliyannis Constantin
 * URI 2768 - Grafo do Dabriel
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 112
#define INF 0x3f3f3f3f

int N, M;
int AG[MAX][MAX][MAX];

void floydWarshall(){
    for(int k = 0; k < N; k++)
        for(int h = 0; h <= k; h++)
            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++)
                    AG[k][i][j] = min(AG[0][i][j], min(AG[k][i][j], AG[k][i][h] + AG[k][h][j]));
}

int main(){
    int u, v, w, k;
    int Q, ans;
    while(scanf("%d %d", &N, &M) != EOF){
        memset(AG, INF, sizeof(AG));
        while(M--){
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            AG[0][u][v] = AG[0][v][u] = w;
            AG[0][u][u] = AG[0][v][v] = 0;
        }
        floydWarshall();
        scanf("%d", &Q);
        while(Q--){
            scanf("%d %d %d", &u, &v, &k);
            u--, v--, k--;
            ans = AG[k][u][v];
            printf("%d\n", (ans != INF) ? ans : -1);
        }
    }
    return 0;
}
