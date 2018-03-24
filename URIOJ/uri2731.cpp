/*
 * Leonardo Deliyannis Constantin
 * URI 2731 - Programação de Viagem
*/

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INFTO ((int)1e9)

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N, E;
vector<vii> LG;
vi path;

int dijkstra(int s, int t){
    vi dist(N+1, INFTO);
    vi parent(N+1, 0);
    dist[s] = 0;
    parent[s] = s;
    priority_queue<ii, vector<ii>, greater<ii> > Q;
    Q.push({0, s});
    while(!Q.empty()){
        int u = Q.top().second; Q.pop();
        if(u == t){
            break;
        }
        for(int i = 0; i < (int)LG[u].size(); i++){
            int v = LG[u][i].first;
            int w = LG[u][i].second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                Q.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
    path.clear();
    int u = t;
    while(parent[u] != u){
        path.push_back(u);
        u = parent[u];
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return dist[t];
}

int main(){
    int u, v, w;
    int D, ans;
	while(scanf("%d %d", &N, &E), N){
        LG.assign(N+1, vii());
        for(int i = 0; i < E; i++){
            scanf("%d %d %d", &u, &v, &w);
            LG[u].push_back({v, w});
            LG[v].push_back({u, w});
        }
        scanf("%d", &D);
        ans = dijkstra(D, 1);
        if(ans <= 120){
            printf("Will not be late. ");
        }else{
            printf("It will be %d minutes late. ", ans - 120);
        }
        printf("Travel time - %d - best way -", ans);
        for(int i = 0; i < (int)path.size(); i++){
            printf(" %d", path[i]);
        }
        printf("\n");
    }
	return 0;
}
