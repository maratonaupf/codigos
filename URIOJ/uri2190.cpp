/*
 * Leonardo Deliyannis Constantin
 * URI 2190 - Rede Ótica
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> edge;
typedef vector<int> vi;
typedef vector<ii> vii;

class UnionFind{
private:
    vi p, rank;
public:
    UnionFind(int N){
        rank.assign(N, 0);
        p.assign(N, 0);
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
            if(rank[x] > rank[y])
                p[y] = x;
            else{
                p[x] = y;
                if(rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
};

vii kruskal(int V, const vector<edge> &els){
    vii ans;
    UnionFind UF(V);
    for(int i = 0; i < (int)els.size(); i++){
        int u = els[i].second.first, v = els[i].second.second;
        if(!UF.isSameSet(u, v)){
            if(u > v)
                swap(u, v);
            ans.push_back({u, v});
            UF.unionSet(u, v);
        }
    }
    return ans;
}

int main(){
    int N, M, tc = 0;
    int i, u, v, w;
    while(scanf("%d %d", &N, &M), N != 0 && M != 0){
        vector<edge> els;
        for(i = 0; i < M; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            els.push_back({w, {u, v}});
        }
        sort(els.begin(), els.end());
        vii ans = kruskal(N, els);
        printf("Teste %d\n", ++tc);
        for(i = 0; i < (int)ans.size(); i++)
            printf("%d %d\n", ans[i].first+1, ans[i].second+1);
        printf("\n");
    }
    return 0;
}
