/*
 * Leonardo Deliyannis Constantin
 * URI 2300 - Transmissão de Energia
*/

#include <stdio.h>
#include <vector>
using namespace std;

typedef vector<int> vi;

class UnionFind{
private:
    vi p, rank;
    int numSets;
public:
    UnionFind(int N){
        numSets = N;
        p.assign(N, 0); rank.assign(N, 0);
        for(int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i){ return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j){ return findSet(i) == findSet(j); }
    void unionSet(int i, int j){
        if(isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        numSets--;
        if(rank[x] > rank[y]){
            p[y] = x;
        }
        else{
            p[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
    }
    int numDisjointSets(){ return numSets; }
};

int main(){
    int E, L, i, u, v, T = 0;
    while(scanf("%d %d", &E, &L), E){
        UnionFind UF(E);
        for(i = 0; i < L; i++){
            scanf("%d %d", &u, &v);
            UF.unionSet(u-1, v-1);
        }
        printf("Teste %d\n", ++T);
        printf("%s\n\n", UF.numDisjointSets() == 1 ? "normal" : "falha");
    }
    return 0;
}
