/*
 * Leonardo Deliyannis Constantin
 * URI 1486 - Circuito Bioquímico Digital
*/

#include <stdio.h>
#include <string.h>
#define MAX 1123

int main(){
    int P, N, C;
    int grid[MAX][MAX];
    int tam[MAX];
    int i, j, ans;
    while(scanf("%d %d %d", &P, &N, &C), P != 0){
        ans = 0;
        memset(tam, 0, sizeof(tam));
        for(i = 0; i <= N; i++){
            for(j = 0; j < P; j++){
                if(i < N){
                    scanf("%d", &grid[i][j]);
                }
                else{
                    grid[i][j] = 0;
                } 
                if(grid[i][j]){
                    tam[j]++;
                }
                else{
                    if(tam[j] >= C) ans++;
                    tam[j] = 0;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
