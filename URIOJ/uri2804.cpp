/*
 * Leonardo Deliyannis Constantin
 * URI 2804 - Ferrovias
*/

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAX 512

int N, AG[MAX][MAX], ans;
bool use[MAX][MAX];

void floydWarshall(){
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(AG[i][j] > AG[i][k] + AG[k][j] && k != i && k != j){
                    ans = -1;
                    return;
                }
}

int main(){
    int K, k, i, j;
    while(scanf("%d %d", &N, &K) != EOF){
        ans = 0;
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                scanf("%d", AG[i]+j);
                if(i > j && AG[i][j] != AG[j][i])
                    ans = -1;
            }
            if(AG[i][i] != 0)
                ans = -1;
        }
        floydWarshall();
        if(ans == -1){
            printf("*\n");
            continue;
        }
        ans = N*(N-1)/2;
        memset(use, -1, sizeof(use));
        for(k = 0; k < N; k++){
            for(i = 0; i < N; i++){
                for(j = i+1; j < N; j++){
                    if(k == i || k == j || i == j)
                        continue;
                    if(AG[i][j] == AG[i][k] + AG[k][j] && use[i][j]){
                        ans--;
                        use[i][j] = 0;
                    }
                }
            }
        }
        printf("%d\n", ans*K);
    }
    return 0;
}
