/*
 * Leonardo Deliyannis Constantin
 * 
*/

#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

typedef vector<int> vi;

int N;
vector<vi> LG;
vector<bool> vis;

void dfs(int s){
    vis[s] = true;
    stack<int> S;
    S.push(s);
    while(!S.empty()){
        int u = S.top();
        S.pop();
        for(int v: LG[u]){
            if(!vis[v]){
                vis[v] = true;
                S.push(v);
            }
        }
    }
}

int main(){
    int M, u, v, ans;
    while(scanf("%d %d", &N, &M) != EOF){
        LG.assign(N, vi());
        while(M--){
            scanf("%d %d", &u, &v);
            u--; v--;
            LG[u].push_back(v);
            LG[v].push_back(u);
        }
        ans = 0;
        vis.assign(N, false);
        for(u = 0; u < N; u++){
            if(!vis[u]){
                dfs(u);
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
