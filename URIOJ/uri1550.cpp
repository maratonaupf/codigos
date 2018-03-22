/*
 * Leonardo Deliyannis Constantin
 * URI 1550 - Inversão
*/

#include <stdio.h>
#include <map>
#include <queue>
#include <vector>
using namespace std;
#define INFTO ((int)1e9)

int invert(int u){
    int ret = 0;
    while(u > 0){
        ret *= 10;
        ret += u % 10;
        u /= 10;
    }
    return ret;
}

int bfs(int s, int t){
    map<int, int> dist;
    dist[s] = 0;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        if(u == t) 
            break;
        vector<int> viz = {u+1, invert(u)};
        for(int v : viz){
            if(!dist.count(v)){
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
    return dist[t];
}

int main(){
	int T, a, b;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &a, &b);
        printf("%d\n", bfs(a, b));
    }
	return 0;
}
