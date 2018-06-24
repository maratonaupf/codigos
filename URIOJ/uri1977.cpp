// Leonardo Deliyannis Constantin
// URI 1977 - Não Posso me Atrasar

#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
using namespace std;
#define INFTO ((int)1e9)
#define LEN 112

typedef pair<string, int> si;
typedef pair<int, string> is;
typedef vector<si> vsi;

map<string, vsi> LG;
map<string, int> dist;
set<string> vtx;

int dijkstra(const string &s, const string &t){
    for(auto it = vtx.begin(); it != vtx.end(); ++it){
        dist[*it] = INFTO;
    }
    dist[s] = 0;
    priority_queue<is, vector<is>, greater<is> > Q;
    Q.push({0, s});
    while(!Q.empty()){
        string u = Q.top().second;
        Q.pop();
        for(int i = 0; i < (int)LG[u].size(); i++){
            string v = LG[u][i].first;
            int w = LG[u][i].second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                Q.push({dist[v], v});
            }
        }
    }
    return dist[t];
}

int main(){
    int X, N, V;
    char o[LEN], d[LEN];
    int t, ans, h, m;
    while(scanf("%d %d %d", &X, &N, &V), X != 0){
        for(int i = 0; i < N; i++){
            scanf("%s %s %d", o, d, &t);
            LG[o].push_back({d, t});
            vtx.insert(o);
            vtx.insert(d);
        }
        ans = (X <= 30 ? 30 : 50) + dijkstra("varzea", "alto");
        h = (17 + (ans / 60)) % 24;
        m = ans % 60;
        printf("%d:%02d\n", h, m);
        printf("%s se atrasar\n", ans > 60 ? "Ira" : "Nao ira");
        LG.clear();
        vtx.clear();
    }
    return 0;
}
