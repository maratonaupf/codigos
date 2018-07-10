/*
 * Leonardo Deliyannis Constantin
 * URI 2784 - Ilhas
*/ 

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INFTO 0x3f3f3f3f

typedef pair<int, int> ii;
typedef vector<ii> vii;

int N, M;
vector<vii> LG;
vector<int> dist;

void dijkstra(int s){
    dist.assign(N, INFTO);
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > Q;
    Q.push({0, s});
    while(!Q.empty()){
        int u = Q.top().second;
        Q.pop();
        for(int i = 0; i < (int)LG[u].size(); i++){
            int v = LG[u][i].first, w = LG[u][i].second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                Q.push({dist[v], v});
            }
        }
    }
}

int main(){
    int i, u, v, w, server;
    int minPing, maxPing;
    while(scanf("%d %d", &N, &M) != EOF){
        LG.assign(N, vii());
        for(i = 0; i < M; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            LG[u].push_back({v, w});
            LG[v].push_back({u, w});
        }
        scanf("%d", &server);
        dijkstra(--server);
        maxPing = 0;
        minPing = INFTO;
        for(u = 0; u < N; u++){
            if(dist[u] != INFTO)
                maxPing = max(dist[u], maxPing);
            if(dist[u] != 0)
                minPing = min(dist[u], minPing);
        }
        printf("%d\n", maxPing - minPing);
    }
    return 0;
}
