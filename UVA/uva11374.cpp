/*
 * Leonardo Deliyannis Constantin
 * UVa 11374 - Airport Express
 */

#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define INFTO ((int)1e9)

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

int N;
vector<viii> LG;

pair<vi, ii> dijkstra(int s, int t){
    int u, sp = -1;
    vi dist(N+1, INFTO), p(N+1, 0);
    dist[s] = 0;
    p[s] = s;
    priority_queue<ii, vii, greater<ii> > Q;
    Q.push({0, s});
    while(!Q.empty()){
        u = Q.top().second; Q.pop();
        if(u == t) break;
        for(auto v : LG[u]){
            if(dist[v.first] > dist[u] + v.second.first){
                dist[v.first] = dist[u] + v.second.first;
                p[v.first] = u;
                if(v.second.second) sp = u;
                Q.push({dist[v.first], v.first});
            }
        }
    }
    vi path;
    while(p[u] != u){
        path.push_back(u);
        u = p[u];
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return make_pair(path, ii(sp, dist[t]));
}

int main(){
    int S, E, M, T = 0;
    int u, v, w, i;
    pair<vi, ii> ans, aux;
    while(scanf("%d %d %d", &N, &S, &E) != EOF){
        if(T++) printf("\n");
        LG.assign(N+1, viii());
        scanf("%d", &M);
        while(M--){
            scanf("%d %d %d", &u, &v, &w);
            LG[u].push_back({v, {w, 0}});
            LG[v].push_back({u, {w, 0}});
        }
        scanf("%d", &M);
        ans = dijkstra(S, E);
        while(M--){
            scanf("%d %d %d", &u, &v, &w);
            LG[u].push_back({v, {w, 1}});
            LG[v].push_back({u, {w, 1}});
            aux = dijkstra(S, E);
            if(aux.second.second < ans.second.second){
                ans = aux;
            }
            LG[u].pop_back();
            LG[v].pop_back();
        }
        for(i = 0; i < (int)ans.first.size(); i++){
            printf("%d", ans.first[i]);
            printf("%c", i < (int)ans.first.size() - 1 ? ' ' : '\n');
        }
        if(ans.second.first != -1)
            printf("%d\n", ans.second.first);
        else
            printf("Ticket Not Used\n");
        printf("%d\n", ans.second.second);
    }
    return 0;
}
