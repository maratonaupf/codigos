/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/115/A
*/

#include <stdio.h>
#include <vector>
#include <stack>
#include <set>
using namespace std;
#define INFTO 112345678

typedef vector<int> vi;

int N;
vector<vi> LG;
vi p, depth;

void dfs(int s){
    depth[s] = 0;
    stack<int> S;
    S.push(s);
    while(!S.empty()){
        int u = S.top(); S.pop();
        for(int v : LG[u]){
            if(depth[v] == INFTO){
                depth[v] = depth[u] + 1;
                S.push(v);
            }
        }
    }
}

int main(){
    int u;
    while(scanf("%d", &N) != EOF){
        LG.assign(N+1, vi());
        p.assign(N+1, -1);
        for(u = 1; u <= N; u++){
            scanf("%d", &p[u]);
            if(p[u] != -1)
                LG[p[u]].push_back(u);
        }
        depth.assign(N+1, INFTO);
        for(u = 1; u <= N; u++)
            if(p[u] == -1)
                dfs(u);
        set<int> groups;
        for(u = 1; u <= N; u++)
            groups.insert(depth[u]);
        printf("%d\n", (int)groups.size());
    }
    return 0;
}
