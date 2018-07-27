/*
 * Leonardo Deliyannis Constantin
 * URI 1835 - Promessa de Campanha
*/

#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

typedef vector<int> vi;

int N, M;
vector<vi> LG;
vector<bool> vis;

void dfs(int s){
    vis[s] = true;
    stack<int> S;
    S.push(s);
    while(!S.empty()){
        int u = S.top();
        S.pop();
        for(int v : LG[u]){
            if(!vis[v]){
                vis[v] = true;
                S.push(v);
            }
        }
    }
}

int main(){
    int T, t, x, y, roadsLeft;
    scanf("%d", &T);
    for(t = 1; t <= T; t++){
        scanf("%d %d", &N, &M);
        LG.assign(N, vi());
        while(M--){
            scanf("%d %d", &x, &y);
            x--, y--;
            LG[x].push_back(y);
            LG[y].push_back(x);
        }
        roadsLeft = -1;
        vis.assign(N, false);
        for(x = 0; x < N; x++){
            if(!vis[x]){
                dfs(x);
                roadsLeft++;
            }
        }
        printf("Caso #%d: ", t);
        if(roadsLeft == 0)
            printf("a promessa foi cumprida\n");
        else
            printf("ainda falta(m) %d estrada(s)\n", roadsLeft);
    }
    return 0;
}
