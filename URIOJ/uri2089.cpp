/*
 * Leonardo Deliyannis Constantin
 * URI 2089 - Lanchonete
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXV 112345
#define MAXN 1123
#define INF ((int)1e9)

typedef vector<int> vi;

int N;
int c[MAXN];
vector<vi> memo;

int possible(int x, int i){
    if(x == 0) return true;
    if(x < 0 || i == N) return false;
    if(memo[x][i] != -1) return memo[x][i];
    return memo[x][i] = possible(x-c[i], i+1) || possible(x, i+1);
}

int main(){
    int V, i;
    while(scanf("%d %d", &V, &N), V != 0){
        for(i = 0; i < N; i++){
            scanf("%d", c+i);
        }
        memo.assign(V+1, vi(N+1, -1));
        printf("%s\n", possible(V, 0) ? "sim" : "nao");
    }
    return 0;
}
