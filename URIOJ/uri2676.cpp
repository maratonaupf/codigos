/*
 * Leonardo Deliyannis Constantin
 * URI 2676 - Cidade no Centro
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

typedef vector<int> vi;

void floydWarshall(vector<vi> &AG){
    int N = (int)AG.size();
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                AG[i][j] = min(AG[i][j], AG[i][k] + AG[k][j]);
}

int main(){
    int N, E, i, u, v, w, ans;
    while(scanf("%d %d", &N, &E), N){
        vector<vi> AG(N, vi(N, INF));
        for(i = 0; i < E; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            AG[u][v] = AG[v][u] = w;
        }
        floydWarshall(AG);
        ans = INF;
        vi dist(N, INF);
        for(u = 0; u < N; u++){
            dist[u] = 0;
            for(v = 0; v < N; v++){
                if(AG[u][v] != INF)
                    dist[u] += AG[u][v];
            }
            if(dist[u] < ans)
                ans = dist[u];
        }
        for(u = 0; u < N; u++){
            if(dist[u] > ans) continue;
            printf("%d ", u+1);
        }
        printf("\n");
    }
    return 0;
}
