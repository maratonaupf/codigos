/*
 * Leonardo Deliyannis Constantin
 * URI 2699 - Enigma
*/

#include <stdio.h>
#include <string.h>
#define MAX 1123

char s[MAX], ans[MAX];
int n, sz;
int dp[MAX][MAX];

int solve(int idx, int val){
    if(idx == sz) return val == 0;
    if(dp[idx][val] != -1) return dp[idx][val];
    if(s[idx] != '?') return solve(idx+1, (val*10 + s[idx] - '0') % n);
    else{
        int i = (idx == 0);
        for(; i < 10; i++){
            if(solve(idx+1, (val*10+i) % n)){
                ans[idx] = '0' + i;
                return 1;
            }
        }
    }
    return dp[idx][val] = 0;
}

int main(){
    while(scanf(" %s %d ", s, &n) != EOF){
        sz = strlen(s);
        strcpy(ans, s);
        memset(dp, -1, sizeof(dp));
        printf("%s\n", solve(0, 0) ? ans : "*");
    }
    return 0;
}
