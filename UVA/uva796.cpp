/*
 * Leonardo Deliyannis Constantin
 * UVa 796 - Critical Links
 */

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

class Graph{
private:
    vector<vi> LG;
    // Hopcroft-Tarjan related variables
    int i, r, fr;
    vi ord, cyc, par;
    vector<bool> art;
    vector<ii> bridges;
    void hopcroftTarjan(int u){
        ord[u] = cyc[u] = i++;
        for(int w : LG[u]){
            if(ord[w] == 0){
                par[w] = u;
                if(u == r) fr++;
                hopcroftTarjan(w);
                if(cyc[w] >= ord[u]) 
                    art[u] = true;
                if(cyc[w] >  ord[u]) 
                    bridges.push_back(ii(min(u, w), max(u, w)));
                cyc[u] = min(cyc[u], cyc[w]);
            } else if(w != par[u]){
                cyc[u] = min(cyc[u], cyc[w]);
            }
        }
    }
public:
    Graph(int N){ LG.assign(N, vi()); }
    void addEdge(int u, int v){ LG[u].push_back(v); }
    vector<ii> findBridges(){
        int N = (int)LG.size();
        i = 1;
        par.assign(N, -1);
        ord.assign(N, 0);
        cyc.assign(N, 0);
        art.assign(N, false);
        bridges.clear();
        for(int s = 0; s < N; s++){
            if(ord[s] == 0){
                r = s; fr = 0; par[r] = r;
                hopcroftTarjan(r);
                if(fr > 1) art[r] = true;
            }
        }
        sort(bridges.begin(), bridges.end());
        return bridges;
    }
};

int main(){
    int N, u, d, v;
    while(scanf("%d", &N) != EOF){
        Graph g(N);
        for(int i = 0; i < N; i++){
            scanf("%d (%d)", &u, &d);
            while(d--){
                scanf("%d", &v);
                g.addEdge(u, v);
            }
        }
        vector<ii> ans = g.findBridges();
        printf("%d critical links\n", (int)ans.size());
        for(ii link : ans)
            printf("%d - %d\n", link.first, link.second);
        printf("\n");
    }
    return 0;
}
