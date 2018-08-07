/*
 * Leonardo Deliyannis Constantin
 * URI 2357 - Violência em Sildávia
*/

#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

typedef vector<int> vi;

int N, M;
vector<vi> LG;
vector<bool> vis;
vi par;

bool dfs(int s){
    vis[s] = true;
    par[s] = s;
    stack<int> S;
    S.push(s);
    while(!S.empty()){
        int u = S.top(); S.pop();
        for(int v : LG[u]){
            if(!vis[v]){
                vis[v] = true;
                par[v] = u;
                S.push(v);
            } else if(v != par[u])
                return true;
        }
    }
    return false;
}

int main(){
    int u, v;
    bool ans;
    while(scanf("%d %d", &N, &M) != EOF){
        LG.assign(N, vi());
        ans = true;
        while(M--){
            scanf("%d %d", &u, &v);
            u--, v--;
            LG[u].push_back(v);
            LG[v].push_back(u);
            if(u == v)
                ans = false;
        }        
        vis.assign(N, false);
        par.assign(N, 0);
        for(u = 0; u < N && ans; u++)
            if(!vis[u] && dfs(u))
                ans = false;
        printf("%seguro\n", ans ? "S" : "Ins");
    }
    return 0;
}
