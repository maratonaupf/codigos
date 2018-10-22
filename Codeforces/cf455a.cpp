/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/455/A
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 112345

typedef long long ll;

int N;
ll cnt[MAX];
ll dp[MAX];

ll solve(int n){
    if(dp[n] != -1LL) return dp[n];
    if(n > 1LL) 
        return dp[n] = max(solve(n-1), solve(n-2) + cnt[n] * (ll)n);
    return dp[n] = (n ? cnt[n] : 0);
}

int main(){
    int i, a, start;
    while(scanf("%d", &N) != EOF){
        memset(cnt, 0, sizeof(cnt));
        start = 0;
        for(i = 0; i < N; i++){
            scanf("%d", &a);
            cnt[a]++;
            start = max(start, a);
        }
        memset(dp, -1LL, sizeof(dp));
        printf("%lld\n", solve(start));
    }
    return 0;
}
