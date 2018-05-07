/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/977/problem/E
*/

#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

typedef vector<int> vi;

int N, M;
vector<vi> LG;
vector<bool> vis;
vector<int> par;

bool dfs(int s){
    int ret = 1;
    vis[s] = true;
    par[s] = s;
    stack<int> S;
    S.push(s);
    while(!S.empty()){
        int u = S.top(); S.pop();
        if((int)LG[u].size() != 2)
            ret = 0;
        for(int v : LG[u]){
            if(!vis[v]){
                vis[v] = true;
                par[v] = u;
                S.push(v);
            }
        }
    }
    return ret;
}

int main(){
    int i, u, v;
    int cycles;
    while(scanf("%d %d", &N, &M) != EOF){
        LG.assign(N, vi());
        for(i = 0; i < M; i++){
            scanf("%d %d", &u, &v);
            u--, v--;
            LG[u].push_back(v);
            LG[v].push_back(u);
        }
        vis.assign(N, false);
        par.assign(N, 0);
        cycles = 0;
        for(u = 0; u < N; u++)
            if(!vis[u])
                cycles += dfs(u);
        printf("%d\n", cycles);
    }
    return 0;
}
