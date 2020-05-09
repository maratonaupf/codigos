/*
 * Leonardo Deliyannis Constantin
 * Demonstração do algoritmo de Kruskal
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// N = número de vértices
// E = número de arestas (Edges)

typedef pair<int, int> ii;
typedef pair<int, ii> edge;

class UnionFind{
private:
    vector<int> pai, rank;
public:
    UnionFind(int N){
        rank.assign(N, 0);
        pai.assign(N, 0);
        for(int u = 0; u < N; u++){
            pai[u] = u;
        }
    }
    int findSet(int u){
        if(u == pai[u])
            return u;
        return pai[u] = findSet(pai[u]);
    }
    bool isSameSet(int u, int v){
        return findSet(u) == findSet(v);
    }
    void unionSet(int u, int v){
        if(isSameSet(u, v))
            return;
        int x = findSet(u);
        int y = findSet(v);
        if(rank[x] > rank[y])
            pai[y] = x;
        else{
            pai[x] = y;
            if(rank[x] == rank[y])
                rank[y]++;
        }
    }
};

int kruskalCost(int N, vector<edge> edgeList){
    UnionFind uf(N);
    int mstCost = 0; // soma do peso das arestas da MST
    // for(int i = 0; i < (int)edgeList.size(); i++){
    for(auto e : edgeList){
        if(!uf.isSameSet(e.second.first, e.second.second)){
            uf.unionSet(e.second.first, e.second.second);
            mstCost += e.first;
        }
    }
    return mstCost;
}

vector<edge> kruskal(int N, vector<edge> edgeList){
    UnionFind uf(N);
    vector<edge> mst; // lista das arestas da MST
    // for(int i = 0; i < (int)edgeList.size(); i++){
    for(auto e : edgeList){
        if(!uf.isSameSet(e.second.first, e.second.second)){
            uf.unionSet(e.second.first, e.second.second);
            mst.push_back(e);
        }
    }
    return mst;
}

int main(){
    int N, E;
    int u, v, w; // origem, destino, peso (weight)
    vector<edge> edgeList;
    while(cin >> N >> E){
        for(int i = 0; i < E; i++){
            cin >> u >> v >> w;
            // edgeList.push_back(edge(w, ii(u, v)));
            edgeList.push_back({w, {u, v}});
        }
        sort(edgeList.begin(), edgeList.end());
        vector<edge> mst = kruskal(N, edgeList);
        for(edge e : mst){
            cout << e.second.first << " " 
                << e.second.second << " "
                << e.first << endl;
        }
        edgeList.clear();
    }
    return 0;
}
