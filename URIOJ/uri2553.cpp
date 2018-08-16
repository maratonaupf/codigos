/*
 * Leonardo Deliyannis Constantin
 * URI 2553 - Passeio em FdI
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX  42
#define MAXT 812

int N, v[MAX], a[MAX];
int dp[MAX][MAXT][MAXT];

int solve(int at, int V, int A){
    if(at == N) return 0;
    if(dp[at][V][A] != -1) return dp[at][V][A];
    if(V+v[at] < 0 || A+a[at] < 0) return solve(at+1, V, A);
    return dp[at][V][A] = 
        max(solve(at+1, V, A), 1 + solve(at+1, V+v[at], A+a[at]));
}

int main(){
    int V, A;
    while(scanf("%d", &N) != EOF){
        scanf("%d %d", &V, &A);
        for(int i = 0; i < N; i++){
            scanf("%d %d", v+i, a+i);
        }
        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(0, V, A));
    }
    return 0;
}
