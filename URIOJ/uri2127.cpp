/*
 * Leonardo Deliyannis Constantin
 * URI 2127 - Sistema Cipoviário
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> edge;

class UnionFind{
private: vector<int> rank, p;
public:
    UnionFind(int N){
        rank.assign(N, 0);
        p.assign(N, 0);
        for(int i = 0; i < N; i++){
            p[i] = i;
        }
    }
    int findSet(int i){ return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j){ return findSet(i) == findSet(j); }
    void unionSet(int i, int j){
        if(isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if(rank[x] > rank[y]) p[y] = x;
        else{
            p[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
    }
};

int kruskal(int N, const vector<edge> &els){
    int mstCost = 0;
    UnionFind uf(N);
    for(edge e : els){
        if(!uf.isSameSet(e.second.first, e.second.second)){
            uf.unionSet(e.second.first, e.second.second);
            mstCost += e.first; 
        }
    }
    return mstCost;
}

int main(){
    int N, M, u, v, c, test = 0;
    while(scanf("%d %d", &N, &M) != EOF){
        vector<edge> els;
        while(M--){
            scanf("%d %d %d", &u, &v, &c);
            u--, v--;
            els.push_back({c, {u, v}});
        }
        sort(els.begin(), els.end());
        printf("Instancia %d\n", ++test);
        printf("%d\n\n", kruskal(N, els));
    }
    return 0;
}
