/*
 * Leonardo Deliyannis Constantin
 * URI 2404 - Reduzindo Detalhes em um Mapa
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

int kruskal(int N, const vector<edge> &els){
    int ans = 0;
    UnionFind UF(N);
    for(int i = 0; i < (int)els.size(); i++){
        edge f = els[i];
        if(!UF.isSameSet(f.second.first, f.second.second)){
            UF.unionSet(f.second.first, f.second.second);
            ans += f.first;
        }
    }
    return ans;
}

int main(){
    int N, M, i, u, v, c;
    while(scanf("%d %d", &N, &M) != EOF){
        vector<edge> els;
        for(i = 0; i < M; i++){
            scanf("%d %d %d", &u, &v, &c);
            els.push_back({c, {u-1, v-1}});
        }
        sort(els.begin(), els.end());
        printf("%d\n", kruskal(N, els));
    }
    return 0;
}
