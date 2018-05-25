/*
 * Leonardo Deliyannis Constantin
 * URI 2562 - Tipos Analógimôn
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind{
private:
    vector<int> rank, p, sz;
    int numSets;
public:
    UnionFind(int N){
        rank.assign(N, 0);
        p.assign(N, 0);
        sz.assign(N, 1);
        numSets = N;
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
            numSets--;
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]){
                p[y] = x;
                sz[x] += sz[y];
            }
            else{
                p[x] = y;
                sz[y] += sz[x];
                if(rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
    int sizeOfSet(int i){ return sz[findSet(i)]; }
    int numDisjointSets(){ return numSets; }
};

int main(){
    int N, M, a, b, E;
    while(scanf("%d %d", &N, &M) != EOF){
        UnionFind UF(N);
        while(M--){
            scanf("%d %d", &a, &b);
            UF.unionSet(a-1, b-1);
        }
        scanf("%d", &E);
        printf("%d\n", UF.sizeOfSet(E-1));
    }
    return 0;
}
