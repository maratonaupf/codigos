#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define INFTO ((int)1e9)

typedef pair<int, int> ii;
typedef vector<ii> vii;

int N, E;
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
            int v = LG[u][i].first;
            int w = LG[u][i].second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                Q.push({dist[v], v});
            }
        }
    }
}

int main(){
    int i, u, v, w;
    int server;
    while(scanf("%d %d", &N, &E) != EOF){
        LG.assign(N, vii());
        for(i = 0; i < E; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            LG[u].push_back({v, w});
            LG[v].push_back({u, w});
        }
        scanf("%d", &server);
        server--;
        dijkstra(server);
        int menor = INFTO;
        int maior = -1;
        for(u = 0; u < N; u++){
            if(dist[u] != 0 && dist[u] < menor)
                menor = dist[u];
            if(dist[u] != INFTO && dist[u] > maior)
                maior = dist[u];
        }
        printf("%d\n", maior-menor);
    }
    return 0;
}
