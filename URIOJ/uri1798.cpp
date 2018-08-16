/*
 * Leonardo Deliyannis Constantin
 * URI 1798 - Cortando Canos
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXN 1123
#define MAXT 2123
#define INF  ((int)1e9)

int N, T;
int dp[MAXN][MAXT];
int c[MAXN], v[MAXN];

int solve(int n, int rem){
    if(n == N || rem == 0) return 0;
    if(rem < 0) return -INF;
    if(dp[n][rem] != -1) return dp[n][rem];
    if(c[n] > rem) return dp[n][rem] = solve(n+1, rem);
    return dp[n][rem] = max(solve(n+1, rem), v[n] + solve(n, rem-c[n]));
}

int main(){
    while(scanf("%d %d", &N, &T) != EOF){
        for(int i = 0; i < N; i++){
            scanf("%d %d", c+i, v+i);
        }
        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(0, T));
    }
    return 0;
}
