/*
 * Leonardo Deliyannis Constantin
 * URI 2327 - Quadrados
*/

#include <stdio.h>
#define MAX 11

int main(){
    int q[MAX][MAX], ans;
    int N, i, j, sum;
    while(scanf("%d", &N) != EOF){
        ans = -1;
        for(i = 0; i < N; i++){
            sum = 0;
            for(j = 0; j < N; j++){
                scanf("%d", q[i]+j);
                sum += q[i][j];
            }
            if(i == 0) ans = sum;
            if(sum != ans) ans = -1;
        }
        for(j = 0; j < N; j++){
            sum = 0;
            for(i = 0; i < N; i++){
                sum += q[i][j];
            }
            if(sum != ans) ans = -1;
        }
        sum = 0;
        for(i = 0; i < N; i++)
            sum += q[i][i];
        if(sum != ans) ans = -1;
        sum = 0;
        for(i = 0; i < N; i++)
            sum += q[i][N-1-i];
        if(sum != ans) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}
