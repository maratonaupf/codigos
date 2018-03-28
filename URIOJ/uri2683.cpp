/*
 * Leonardo Deliyannis Constantin
 * URI 2683 - Espaço de Projeto
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> edge;
typedef vector<int> vi;

class UnionFind{
private:
    vi rank, p;
public:
    UnionFind(int N){
        p.assign(N, 0); rank.assign(N, 0);
        for(int i = 0; i < N; i++){ p[i] = i; }
    }
    int findSet(int i){
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]) { p[y] = x; }
            else { 
                p[x] = y; 
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int V, N;
vector<edge> els;

int kruskal(){
    int mstCost = 0;
    UnionFind UF(V+1);
    for(int i = N-1; i >= 0; i--){
        edge f = els[i];
        if(!UF.isSameSet(f.second.first, f.second.second)){
            mstCost += f.first;
            UF.unionSet(f.second.first, f.second.second);
        }
    }
    return mstCost;
}

int main(){
    int i, u, v, w;
    while(scanf("%d", &N) != EOF){
        els.assign(N, edge());
        V = 0;
        for(i = 0; i < N; i++){
            scanf("%d %d %d", &u, &v, &w);
            els[i] = edge(w, {u, v});
            V = max(V, max(u, v));
        }
        sort(els.begin(), els.end());
        printf("%d\n", kruskal());
        reverse(els.begin(), els.end());
        printf("%d\n", kruskal());
    }
    return 0;
}
