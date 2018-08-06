/*
 * Leonardo Deliyannis Constantin
 * URI 2293 - Campo de Minhocas
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 112

int main(){
    int N, M, i, j, x, row[MAX], col[MAX], ans;
    while(scanf("%d %d", &N, &M) != EOF){
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        ans = 0;
        for(i = 0; i < N; i++){
            for(j = 0; j < M; j++){
                scanf("%d", &x);
                row[i] += x;
                col[j] += x;
                ans = max(ans, max(row[i], col[j]));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
