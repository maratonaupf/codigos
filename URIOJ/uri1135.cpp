/*
 * Leonardo Deliyannis Constantin
 * URI 1135 - Colônia de Formigas 
*/ 

#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define MAX 100005   //        10^5, adjust accordingly
#define LOG_TWO_N 18 // 2^18 > 10^5, adjust accordingly
#define INFTO 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int N;
int parent[MAX][LOG_TWO_N];
vector<vii> LG;
vector<int> depth; 
vector<ll> dist;

void dfs(int s){
    depth.assign(N, INFTO);
    dist.assign(N, INFTO);
    depth[s] = dist[s] = 0;
    parent[s][0] = 0; // try with both 0 and -1
    stack<int> S;
    S.push(s);
    while(!S.empty()){
        int u = S.top(); 
        S.pop();
        for(int i = 0; i < (int)LG[u].size(); i++){
            int v = LG[u][i].first, w = LG[u][i].second;
            if(depth[v] == INFTO){
                depth[v] = depth[u] + 1;
                dist[v] = dist[u] + (ll)w;
                parent[v][0] = u;
                S.push(v);
            }
        }
    }
}

void precomputeSparseTable(){
    for(int i = 1; i < LOG_TWO_N; i++){
        for(int u = 0; u < N; u++){
            if(parent[u][i-1] != -1){
                parent[u][i] = parent[parent[u][i-1]][i-1];
            }
        }
    }
}

int LCA(int u, int v){
    if(depth[u] > depth[v])
        swap(u, v);
    int diff = depth[v] - depth[u];
    for(int i = 0; i < LOG_TWO_N; i++)
        if((diff>>i)&1)
            v = parent[v][i];
    if(u == v)
        return u;
    for(int i = LOG_TWO_N-1; i >= 0; i--){
        if(parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main(){
    int u, v, w, Q;
    while(scanf("%d", &N), N != 0){
        LG.assign(N, vii());
        for(u = 1; u < N; u++){
            scanf("%d %d", &v, &w);
            if(u < v)
                LG[u].push_back({v, w});
            else
                LG[v].push_back({u, w});
        }
        dfs(0);
        precomputeSparseTable();
        scanf("%d", &Q);
        while(Q--){
            scanf("%d %d", &u, &v);
            int lca = LCA(u, v);
            ll ans = (dist[u] - dist[lca]) + (dist[v] - dist[lca]);
            printf("%lld%c", ans, Q > 0 ? ' ' : '\n');
        }
    }
    return 0;
}
