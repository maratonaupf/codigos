/*
 * Leonardo Deliyannis Constantin
 * URI 2173 - Caixa Dois
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
        for(int i = 0; i < N; i++) p[i] = i;
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
            UF.unionSet(e.second.first, e.second.second);
            mstCost += e.first;
        }
    }
    return mstCost;
}

int main(){
    int N, M, x, y, c, ans;
    while(scanf("%d %d", &N, &M), N != 0){
        vector<edge> els;
        while(M--){
            scanf("%d %d %d", &x, &y, &c);
            x--; y--;
            els.push_back({c, {x, y}});
        }
        sort(els.begin(), els.end());
        ans = -kruskal(N, els);
        reverse(els.begin(), els.end());
        ans += kruskal(N, els);
        printf("%d\n", ans);
    }
    return 0;
}
