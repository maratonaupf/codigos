/*
 * Leonardo Deliyannis Constantin
 * 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INFTO ((int)1e9)

typedef vector<int> vi;

int N, E;
vector<vi> LG;
vector<int> dist;

int bfs(int s, int t){
    dist.assign(N, INFTO);
    dist[s] = 0;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        // if(u == t) break;
        for(int v : LG[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
    return dist[t];
}

int main(){
    char a, b;
    int u, v, i, Q;
    while(cin >> N >> E){
        LG.assign(N, vi());
        for(i = 0; i < E; i++){
            cin >> a >> b;
            u = a - 'A';
            v = b - 'A';
            LG[u].push_back(v);
            LG[v].push_back(u);
        }
        cin >> Q;
        while(Q--){
            cin >> a >> b;
            u = a - 'A';
            v = b - 'A';
            cout << bfs(u, v) << endl;
        }
    }
    return 0;
}
