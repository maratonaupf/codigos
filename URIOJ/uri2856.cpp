/*
 * Leonardo Deliyannis Constantin
 * URI 2856 - Viagem do Pão de Queijo
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 1123

int N, R;
int x[MAX], z[MAX], y[MAX];
int dp[MAX][MAX][8];

int solve(int n, int r, int m){
    if(dp[n][r][m] != -1) return dp[n][r][m];
    if(n == N) return dp[n][r][m] = 0;
    if(r < y[n] || __builtin_popcount(m | z[n]) > 2)
        return dp[n][r][m] = solve(n+1, r, m);
    return dp[n][r][m] = max(solve(n+1, r, m), 
        solve(n+1, r-y[n], m | z[n]) + x[n]);
}

int main(){
    char f;
    while(scanf("%d %d", &N, &R) != EOF){
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < N; i++){
            scanf("%d %c %d", x+i, &f, y+i);
            z[i] = (f == 'G') ? 1 : (f == 'B') ? 2 : 4;
        }
        printf("%d\n", solve(0, R, 0));
    }
    return 0;
}
