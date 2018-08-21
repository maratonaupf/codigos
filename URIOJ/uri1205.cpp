/*
 * Leonardo Deliyannis Constantin
 * URI 1205 - Cerco a Leningrado
*/

#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> ii;
typedef vector<int> vi;

int N;
vector<vi> LG;
vi sh;

int dijkstra(int s, int t){
    vi dist(N+1, INF);
    dist[s] = sh[s];
    priority_queue<ii, vector<ii>, greater<ii> > Q;
    Q.push({dist[s], s});
    while(!Q.empty()){
        int u = Q.top().second; Q.pop();
        for(int v : LG[u]){
            if(dist[v] > dist[u] + sh[v]){
                dist[v] = dist[u] + sh[v];
                Q.push({dist[v], v});
            }
        }
    }
    return dist[t];
}

int main(){
    int M, K, A, C;
    int u, v, s, t;
    double P, ans;
    while(scanf("%d %d %d %lf", &N, &M, &K, &P) != EOF){
        LG.assign(N+1, vi());
        sh.assign(N+1, 0);
        while(M--){
            scanf("%d %d", &u, &v);
            LG[u].push_back(v);
            LG[v].push_back(u);
        }
        scanf("%d", &A);
        while(A--){
            scanf("%d", &u);
            sh[u]++;
        }
        scanf("%d %d", &s, &t);
        C = dijkstra(s, t);
        ans = (K < C) ? 0.0 : pow(P, C);
        printf("%.3lf\n", ans);
    }
    return 0;
}
