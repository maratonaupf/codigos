/*
 * Leonardo Deliyannis Constantin
 * URI 2550 - Novo Campus
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> edge;

class UnionFind{
private: 
    vector<int> p, rank, sz;
    int numSets;
public:
    UnionFind(int N){
        p.assign(N, 0); rank.assign(N, 0); sz.assign(N, 1);
        numSets = N;
        for(int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i){ return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j){ return findSet(i) == findSet(j); }
    void unionSet(int i, int j){
        if(!isSameSet(i, j)){ 
            numSets--;
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]){
                p[y] = x;
                sz[x] += sz[y];
            }
            else{
                p[x] = y;
                sz[y] += sz[x];
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
    int numDisjointSets(){ return numSets; }
    int sizeOfSet(int i){ return sz[findSet(i)]; }
};

int kruskal(int N, const vector<edge> &els){
    int ret = 0;
    UnionFind UF(N);
    for(edge e : els){
        if(!UF.isSameSet(e.second.first, e.second.second)){
            UF.unionSet(e.second.first, e.second.second);
            ret += e.first;
        }
    }
    return (UF.numDisjointSets() == 1) ? ret : -1;
}

int main(){
    int N, M, u, v, w, ans;
    while(scanf("%d %d", &N, &M) != EOF){
        vector<edge> els;
        while(M--){
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            els.push_back({w, {u, v}});
        }
        sort(els.begin(), els.end());
        ans = kruskal(N, els);
        (ans != -1) ? printf("%d\n", ans) : printf("impossivel\n");
    }
    return 0;
}
