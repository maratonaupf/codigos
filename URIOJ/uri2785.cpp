/*
 * Leonardo Deliyannis Constantin
 * URI 2785 - Pirâmide
*/ 

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 112

int N, mat[MAX][MAX];
int sum[MAX][MAX][MAX];

int main(){
    int i, j, k;
    while(scanf("%d", &N) != EOF){
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                scanf("%d", &mat[i][j]);
            }
        }
        for(i = 0; i < N; i++){
            for(k = 0; k+i < N; k++){
                sum[i][k][k+i] = (i == 0) ? 0 : 
                    min(sum[i-1][k+1][k+i], sum[i-1][k][k+i-1]);
                for(j = k; j <= k+i; j++){
                    sum[i][k][k+i] += mat[i][j];
                }
            }
        }
        printf("%d\n", sum[N-1][0][N-1]);
    }
    return 0;
}
