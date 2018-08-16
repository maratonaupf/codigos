/*
 * Leonardo Deliyannis Constantin
 * URI 1862 - Casas de Westeros
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1123

class UnionFind{
private:
    vector<int> p, rank, setSize;
    int numSets;
public:
    UnionFind(int N){
        p.assign(N, 0); rank.assign(N, 0);
        numSets = N;
        setSize.assign(N, 1);
        for(int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i){ return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j){ return findSet(i) == findSet(j); }
    void unionSet(int i, int j){
        if(isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if(rank[x] > rank[y]){
            p[y] = x; setSize[x] += setSize[y];
        }
        else{
            p[x] = y; setSize[y] += setSize[x];
            if(rank[x] == rank[y]) rank[y]++;
        }
        numSets--;
    }
    int numDisjointSets(){ return numSets; }
    int sizeOfSet(int i){ return setSize[findSet(i)]; }
};

int main(){
    int N, i, j;
    char grid[MAX][MAX];
    bool ans;
    while(scanf("%d ", &N) != EOF){
        UnionFind UF(N);
        for(i = 0; i < N; i++){
            fgets(grid[i], MAX, stdin);
            for(j = 0; j < N; j++)
                if(grid[i][j] == 'S')
                    UF.unionSet(i, j);
        }
        ans = true;
        for(i = 0; i < N && ans; i++)
            for(j = 0; j < N && ans; j++)
                if((grid[i][j] == 'S') ^ UF.isSameSet(i, j))
                    ans = false;
        if(!ans){
            printf("-1\n");
            continue;
        }
        vector<int> sz;
        vector<bool> memo(MAX, false);
        int num = UF.numDisjointSets();
        printf("%d\n", num);
        for(i = 0; i < N; i++){
            if(!memo[UF.findSet(i)]){
                memo[UF.findSet(i)] = true;
                sz.push_back(UF.sizeOfSet(i));
            }
        }
        sort(sz.rbegin(), sz.rend());
        for(i = 0; i < num; i++){
            printf("%d%c", sz[i], (i < num - 1) ? ' ' : '\n');
        }
    }
    return 0;
}
