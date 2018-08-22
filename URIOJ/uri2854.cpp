/*
 * Leonardo Deliyannis Constantin
 * URI 2854 - Árvore Genealógica
*/

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
#define LEN 1123

typedef vector<int> vi;

class UnionFind{
private: vi p, rank;
    int numSets;
public:
    UnionFind(int N){
        p.assign(N, 0);
        rank.assign(N, 0);
        numSets = N;
        for(int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i){ return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j){ return findSet(i) == findSet(j); }
    void unionSet(int i, int j){
        if(isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        numSets--;
        if(rank[x] > rank[y])
            p[y] = x;
        else{
            p[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
    }
    int numDisjointSets(){ return numSets; }
};

int main(){
    int M, N, cnt;
    char u[LEN], v[LEN];
    while(scanf("%d %d", &M, &N) != EOF){
        UnionFind UF(M);
        unordered_map<string, int> hash;
        cnt = 0;
        while(N--){
            scanf(" %s %*s %s", u, v);
            if(!hash.count(u)) hash[u] = cnt++;
            if(!hash.count(v)) hash[v] = cnt++;
            UF.unionSet(hash[u], hash[v]);
        }
        printf("%d\n", UF.numDisjointSets());
    }
    return 0;
}
