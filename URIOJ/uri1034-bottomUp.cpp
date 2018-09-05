/*
 * Leonardo Deliyannis Constantin
 * URI 1034 - Festival de Estátuas de Gelo
*/

#include <stdio.h>
#include <string.h>
#define MAXN 32
#define MAXM 1123456
#define INF 0x3f3f3f3f
#define min(a, b) ((a) < (b) ? (a) : (b))

int main(){
    int T, N, M, x, i;
    int c[MAXN];
    int dp[MAXM];
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        for(i = 0; i < N; i++)
            scanf("%d", c+i);
        dp[0] = 0;
        for(x = 1; x <= M; x++){
            dp[x] = INF;
            for(i = 0; i < N; i++)
                if(x-c[i] >= 0)
                    dp[x] = min(dp[x], dp[x-c[i]] + 1);
        }
        printf("%d\n", dp[M]);
    }
    return 0;
}
