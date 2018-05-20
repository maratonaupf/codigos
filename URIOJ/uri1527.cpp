/*
 * Leonardo Deliyannis Constantin
 * URI 1527 - Guildas
*/

#include <stdio.h>
#include <vector>
using namespace std;
#define MAX 112345

class UnionFind{
private: vector<int> p, rank, lv, wins;
public:
    UnionFind(int N){
        p.assign(N, 0); 
        rank.assign(N, 0);
        lv.assign(N, 0);
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
            if(rank[x] > rank[y]){
                p[y] = x;
                lv[x] += lv[y];
            }
            else{ 
                p[x] = y;
                lv[y] += lv[x];
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
    void setLevel(int i, int val){ lv[i] = val; }
    int getLevel(int i){ return lv[findSet(i)]; }
};

int main(){
    int N, M, i, lv, la, lb;
    int Q, A, B, ans, gr, ga, gb;
    while(scanf("%d %d", &N, &M), N != 0){
        UnionFind UF(N);
        for(i = 0; i < N; i++){
            scanf("%d", &lv);
            UF.setLevel(i, lv);
        }
        ans = 0;
        while(M--){
            scanf("%d %d %d", &Q, &A, &B);
            A--, B--;
            if(Q == 1) UF.unionSet(A, B);
            else{
                gr = UF.findSet(0);
                ga = UF.findSet(A),  gb = UF.findSet(B);
                la = UF.getLevel(A), lb = UF.getLevel(B);
                if((gr == ga && la > lb) || (gr == gb && lb > la)) 
                    ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
