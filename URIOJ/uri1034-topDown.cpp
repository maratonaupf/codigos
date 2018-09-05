/*
 * Leonardo Deliyannis Constantin
 * URI 1034 - Festival de Estátuas de Gelo
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXN 32
#define MAXM 1123456
#define INF 0x3f3f3f3f

int N, M;
int c[MAXN];
int dp[MAXM];

int solve(int x){
    if(x < 0) return INF;
    if(dp[x] != -1) return dp[x];
    if(x == 0) return dp[x] = 0;
    int ans = INF;
    for(int i = 0; i < N; i++){
        ans = min(ans, solve(x-c[i]) + 1);
    }
    return dp[x] = ans;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        for(int i = 0; i < N; i++)
            scanf("%d", c+i);
        memset(dp, -1, sizeof dp);
        printf("%d\n", solve(M));
    }
    return 0;
}
