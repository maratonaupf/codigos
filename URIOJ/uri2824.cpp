/*
 * Leonardo Deliyannis Constantin
 * URI 2824 - Pudim
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 5123

int memo[MAX][MAX];

int lcs(const char *X, const char *Y, int i, int j){
    if(memo[i][j] != -1)
        return memo[i][j];
    if(i == 0 || j == 0)
        return memo[i][j] = 0;
    if(X[i-1] == Y[j-1])
        return memo[i][j] = 1 + lcs(X, Y, i-1, j-1);
    return memo[i][j] = max(lcs(X, Y, i-1, j), lcs(X, Y, i, j-1));
}

int main(){
    char s[MAX], t[MAX];
    while(fgets(s, MAX, stdin) != NULL){
        fgets(t, MAX, stdin);
        memset(memo, -1, sizeof(memo));
        printf("%d\n", lcs(s, t, strlen(s)-1, strlen(t)-1));
    }
    return 0;
}
