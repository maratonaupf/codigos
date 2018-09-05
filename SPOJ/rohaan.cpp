/*
 * Leonardo Deliyannis Constantin
 * https://www.spoj.com/problems/ROHAAN/
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 52

void floydWarshall(int N, int AG[MAX][MAX]){
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                AG[i][j] = min(AG[i][j], AG[i][k] + AG[k][j]);
}

int main(){
    int T, tc, N, i, j, AG[MAX][MAX], Q, ans;
    scanf("%d", &T);
    for(tc = 1; tc <= T; tc++){
        scanf("%d", &N);
        for(i = 0; i < N; i++)
            for(j = 0; j < N; j++)
                scanf("%d", AG[i]+j);
        floydWarshall(N, AG);
        ans = 0;
        scanf("%d", &Q);
        while(Q--){
            scanf("%d %d", &i, &j);
            i--, j--;
            ans += AG[i][j];
        }
        printf("Case #%d: %d\n", tc, ans);
    }
    return 0;
}
