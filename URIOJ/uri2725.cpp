/*
 * Leonardo Deliyannis Constantin
 * URI 2725 - Vila Natalina
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1123

typedef pair<int, int> ii;
typedef pair<int, ii> edge;

class UnionFind{
private: vector<int> p, rank;
public:
    UnionFind(int N){
        p.assign(N, 0); rank.assign(N, 0);
        for(int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i){
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j){
        if(isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if(rank[x] > rank[y]){
            p[y] = x;
        }
        else{
            p[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
    }
};

int kruskal(int N, const vector<edge> &els){
    int ans = 0;
    UnionFind UF(N);
    for(edge e : els){
        if(!UF.isSameSet(e.second.first, e.second.second)){
            UF.unionSet(e.second.first, e.second.second);
            ans+= e.first;
        }
    }
    return ans;
}

int gcd(int a, int b){ return (b == 0) ? a : gcd(b, a%b); }

int main(){
    int T, N, K, i, j, x[MAX], y[MAX];
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &K);
        vector<edge> els;
        for(i = 0; i < N; i++){
            scanf("%d %d", x+i, y+i);
            for(j = 0; j < i; j++){
                els.push_back({gcd(abs(x[i]-x[j]), abs(y[i]-y[j]))-1, {i, j}});
            }
        }
        sort(els.begin(), els.end());
        printf("%d\n", kruskal(N, els) * K);
    }
    return 0;
}
