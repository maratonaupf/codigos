/*
 * Leonardo Deliyannis Constantin
 * Demonstração do algoritmo de Prim
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1123

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// vi taken;
vector<bool> taken;
priority_queue<ii, vector<ii>, greater<ii> > pq;

void process(int u, const vector<vii> &adjList){
    taken[u] = true;
    for(int j = 0; j < (int)adjList[u].size(); j++){
        ii v = adjList[u][j];
        if(!taken[v.first]){
            pq.push({v.second, v.first});
        }
    }
}

int prim(const vector<vii> &adjList){
    int N = (int)adjList.size();
    taken.assign(N, false);
    process(0, adjList);
    int mstCost = 0;
    while(!pq.empty()){
        ii front = pq.top();
        pq.pop();
        int u = front.second;
        int w = front.first;
        if(!taken[u]){
            mstCost += w;
            process(u, adjList);
        }
    }
    return mstCost;
}

int main(){
    int N, E;
    int u, v, w; // origem, destino, peso (weight)
    while(cin >> N >> E){
        vector<vii> adjList;
        adjList.assign(N, vii());
        for(int i = 0; i < E; i++){
            cin >> u >> v >> w;
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }
        int mstCost = prim(adjList);
        cout << mstCost << endl;
    }
    return 0;
}
