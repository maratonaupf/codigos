/*
 * Leonardo Deliyannis Constantin
 * URI 2776 - Promoções
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXN 1123
#define MAXM 2123
#define INF 0x3f3f3f3f

int N, M;
int memo[MAXN][MAXM];
int Q[MAXN], V[MAXN];

int pd(int i, int w){
    if(i == 0)
        return (w == 0) ? 0 : -INF;
    if(memo[i][w] != -1)
        return memo[i][w];
    if(Q[i] > w)
        return memo[i][w] = pd(i-1, w);
    return memo[i][w] = max(pd(i-1, w), 
        max(pd(i-1, w-Q[i]) + V[i], pd(i, w-Q[i]) + V[i]));
} 

int main(){
    int i;
    while(scanf("%d %d", &N, &M) != EOF){
        for(i = 1; i <= N; i++){
            scanf("%d %d", &Q[i], &V[i]);
        }
        memset(memo, -1, sizeof(memo));
        printf("%d\n", pd(N, M));
    }
    return 0;
}
