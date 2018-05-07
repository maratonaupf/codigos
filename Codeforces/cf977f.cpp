/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/977/problem/F
*/

#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
#define MAX 212345

int main(){
    int N, i, a[MAX];
    int ans, lst;
    while(scanf("%d", &N) != EOF){
        map<int, int> dp;
        ans = 0;
        for(i = 0; i < N; i++){
            scanf("%d", a+i);
            dp[a[i]] = max(dp[a[i]], dp[a[i]-1] + 1);
            ans = max(ans, dp[a[i]]);
        }
        lst = -1;
        for(i = 0; i < N; i++){
            if(dp[a[i]] == ans){
                lst = a[i];
            }
        }
        assert(lst != -1);
        vector<int> idx;
        for(i = N-1; i >= 0; i--){
            if(a[i] == lst){
                idx.push_back(i+1);
                lst--;
            }
        }
        printf("%d\n", (int)idx.size());
        for(i = (int)idx.size()-1; i >= 0; i--){
            printf("%d%c", idx[i], (i > 0) ? ' ' : '\n');
        }
    }
    return 0;
}
