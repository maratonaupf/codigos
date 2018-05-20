/*
 * Leonardo Deliyannis Constantin
 * URI 2380 - Fusões
*/

#include <stdio.h>
#include <vector>
using namespace std;

class UnionFind{
private: vector<int> p, rank;
public:
    UnionFind(int N){
        p.assign(N, 0); rank.assign(N, 0);
        for(int i = 0; i < N; i++){
            p[i] = i;
        }
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

int main(){
    int N, K, b1, b2;
    char Q;
    while(scanf("%d %d", &N, &K) != EOF){
        UnionFind UF(N);
        while(K--){
            scanf(" %c %d %d", &Q, &b1, &b2);
            b1--, b2--;
            if(Q == 'F')
                UF.unionSet(b1, b2);
            else
                printf("%c\n", UF.isSameSet(b1, b2) ? 'S' : 'N');
        }
    }
    return 0;
}
