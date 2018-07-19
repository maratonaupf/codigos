/*
 * Leonardo Deliyannis Constantin
 * URI 2825 - L de Atreus!?
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define LEN 112
#define MAX 1123

int memo[LEN][LEN];

int editDist(const char *n, const char *m, int a, int b){
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            if(i == 0) memo[i][j] = j;
            else if(j == 0) memo[i][j] = i;
            else if(n[i-1] == m[j-1]) memo[i][j] = memo[i-1][j-1];
            else memo[i][j] = 1 + min(memo[i-1][j-1], 
                min(memo[i][j-1], memo[i-1][j]));
        }
    }
    return memo[a][b];
}

int main(){
    int q, i, c, ans;
    int ed[MAX];
    char v[MAX][LEN], s[LEN];
    while(scanf("%d ", &q) != EOF){
        for(i = 0; i < q; i++){
            scanf("%s", v[i]);
        }
        scanf("%d ", &c);
        while(c--){
            scanf("%s", s);
            ans = 0;
            for(i = 0; i < q; i++){
                ed[i] = editDist(s, v[i], strlen(s), strlen(v[i]));
                if(ed[i] < ed[ans])
                    ans = i;
            }
            printf("%s%c", v[ans], c > 0 ? ' ' : '\n');
        }
    }
    return 0;
}
