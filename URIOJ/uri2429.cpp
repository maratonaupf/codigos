/*
 * Leonardo Deliyannis Constantin
 * URI 2429 - Rodovia
*/

#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;
#define DFS_WHITE (-1)

typedef vector<int> vi;

int N;
vector<vi> LG;
vector<bool> vis;
vi low, num, S;
int ncomp, cnt;

void tarjan(int u){
    low[u] = num[u] = cnt++;
    S.push_back(u);
    vis[u] = 1;
    for(int v : LG[u]){
        if(num[v] == DFS_WHITE)
            tarjan(v);
        if(vis[v])
            low[u] = min(low[u], low[v]);
    }
    if(low[u] == num[u]){
        ++ncomp;
        while(true){
            int v = S.back(); S.pop_back(); vis[v] = 0;
            if(u == v) break;
        }
    }
}

int main(){
    int i, u, v;
    while(scanf("%d", &N) != EOF){
        LG.assign(N, vi());
        for(i = 0; i < N; i++){
            scanf("%d %d", &u, &v);
            u--, v--;
            LG[u].push_back(v);
        }
        num.assign(N, DFS_WHITE);
        low.assign(N, 0);
        vis.assign(N, false);
        ncomp = cnt = 0;
        S.clear();
        for(u = 0; u < N; u++)
            if(num[u] == DFS_WHITE)
                tarjan(u);
        printf("%c\n", ncomp > 1 ? 'N' : 'S');
    }
    return 0;
}
