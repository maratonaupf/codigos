/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/520/B
*/

#include <stdio.h>
#include <queue>
#include <map>
using namespace std;
#define MAX ((int)1e4)

typedef vector<int> vi;

map<int, int> dist;

int bfs(int s, int t){
    dist.clear();
    dist[s] = 0;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        if(u == t)
            break;
        vi LG = { u-1, u*2 };
        for(int v : LG){
            if(v < 0 || MAX < v)
                continue;
            if(!dist.count(v) || dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
    if(dist.count(t))
        return dist[t];
    return -1;
}

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        printf("%d\n", bfs(n, m));
    }
    return 0;
}
