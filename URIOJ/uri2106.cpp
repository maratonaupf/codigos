/*
 * Leonardo Deliyannis Constantin
 * URI 2106 - Montagem
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 18
#define INF 0x3f3f3f3f

int N, c[MAX][MAX];
int dp[1 << MAX];

int cost(int mask, int p){
    if(dp[mask] != -1) return dp[mask];
    int ans = INF;
    for(int i = 0; i < N; i++)
        if(!(mask & (1<<i)))
            ans = min(ans, cost(mask | (1 << i), p+1) + c[p][i]);
    return dp[mask] = ans;
}

int main(){
    while(scanf("%d", &N), N){
        for(int i = 0; i < N; i++)
            for(int k = 0; k < N; k++)
                scanf("%d", c[i]+k);
        memset(dp, -1, sizeof(dp));
        dp[(1<<N)-1] = 0;
        printf("%d\n", cost(0, 0));
    }
    return 0;
}
