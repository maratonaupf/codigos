/*
 * Leonardo Deliyannis Constantin
 * URI 1409 - Zak Galou
*/

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 1123

typedef vector<int> vi;
typedef pair<int, int> ii;

struct magic{
    int mana, dmg;
    magic(){ mana = dmg = 0; }
    magic(int m, int d): mana(m), dmg(d) {}
};

int M, N, G, K;
vector<magic> mag;
vector<vi> LG;
vi cost, S;

void DP(){
    S.assign(MAX, INF);
    int lf, i;
    for(lf = 0; lf < MAX; lf++){
        for(i = 0; i < M; i++){
            if(mag[i].dmg >= lf)
                S[lf] = min(S[lf], mag[i].mana);
            else 
                S[lf] = min(S[lf], mag[i].mana + S[lf - mag[i].dmg]);
        }
    }
}

int dijkstra(int s, int t){
    vi dist(N, INF);
    dist[s] = cost[s];
    priority_queue<ii, vector<ii>, greater<ii> > q;
    q.push({dist[s], s});
    while(!q.empty()){
        int u = q.top().second; q.pop();
        if(u == t) return dist[t];
        for(int v : LG[u]){
            if(dist[v] > dist[u] + cost[v]){
                dist[v] = dist[u] + cost[v];
                q.push({dist[v], v});
            }
        }
    }
    return -1;
}

int main(){
    int i, a, b, lf;
    while(scanf("%d %d %d %d", &M, &N, &G, &K), M){
        mag.assign(M, magic());
        LG.assign(N, vi());
        cost.assign(N, 0);
        for(i = 0; i < M; i++){
            scanf("%d %d", &mag[i].mana, &mag[i].dmg);
        }
        DP();
        for(i = 0; i < G; i++){
            scanf("%d %d", &a, &b);
            a--, b--;
            LG[a].push_back(b);
            LG[b].push_back(a);
        }
        for(i = 0; i < K; i++){
            scanf("%d %d", &a, &lf);
            cost[a-1] += S[lf];
        }
        printf("%d\n", dijkstra(0, N-1));
    }
    return 0;
}
