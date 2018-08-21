/*
 * Leonardo Deliyannis Constantin
 * URI 1955 - See World
*/

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f

typedef vector<int> vi;

int N;
vector<vi> LG;

bool isBipartite(int s){
    queue<int> Q;
    Q.push(s);
    vi color(N, INF);
    color[s] = 0;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int v : LG[u]){
            if(color[v] == INF){
                color[v] = !color[u];
                Q.push(v);
            }
            else if(color[v] == color[u])
                return false;
        }
    }
    return true;
}

int main(){
    int u, v, w;
    while(scanf("%d", &N) != EOF){
        LG.assign(N, vi());
        for(u = 0; u < N; u++){
            for(v = 0; v < N; v++){
                scanf("%d", &w);
                if(!w) LG[u].push_back(v);
            }
        }
        printf("%s!\n", isBipartite(0) ? "Bazinga" : "Fail");
    }
    return 0;
}
