/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/500/A
*/

#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

typedef vector<int> vi;

int n;
vector<vi> LG;

bool dfs(int s, int t){
    vector<bool> vis(n+1, false);
    vis[s] = true;
    stack<int> S;
    S.push(s);
    while(!S.empty()){
        int u = S.top(); S.pop();
        if(u == t)
            break;
        for(int v : LG[u]){
            if(!vis[v]){
                vis[v] = true;
                S.push(v);
            }
        }
    }
    return vis[t];
}

int main(){
    int t, a;
    while(scanf("%d %d", &n, &t) != EOF){
        LG.assign(n+1, vi());
        for(int i = 1; i < n; i++){
            scanf("%d", &a);
            LG[i].push_back(i+a);
        }
        printf("%s\n", dfs(1, t) ? "YES" : "NO");
    }
    return 0;
}
