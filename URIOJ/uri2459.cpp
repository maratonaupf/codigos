/*
 * Leonardo Deliyannis Constantin
 * URI 2459 - Copa do Mundo
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> edge;

class UnionFind{
private:
    vector<int> p, rank;
public:
    UnionFind(int N){
        p.assign(N, 0);
        rank.assign(N, 0);
        for(int i = 0; i < N; i++)
            p[i] = i;
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
            if(rank[x] > rank[y]) p[y] = x;
            else{
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int kruskal(int N, const vector<edge> &els){
    int mstCost = 0;
    UnionFind UF(N);
    for(edge e : els){
        if(!UF.isSameSet(e.second.first, e.second.second)){
            mstCost += e.first;
            UF.unionSet(e.second.first, e.second.second);
        }
    }
    return mstCost;
}

int main(){
    int N, F, R, i, u, v, w;
    while(scanf("%d %d %d", &N, &F, &R) != EOF){
        vector<edge> els;
        for(i = 0; i < F+R; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--; v--;
            els.push_back({w, {u, v}});
        }
        sort(els.begin(), els.begin()+F);
        sort(els.begin()+F, els.end());
        printf("%d\n", kruskal(N, els));
    }
    return 0;
}
