/*
 * Leonardo Deliyannis Constantin
 * URI 2450 - Matriz Escada
*/

#include <stdio.h>
#define MAX 512

int main(){
    int N, M, i, j;
    int grid[MAX][MAX];
    int zeros[MAX], esq[MAX];
    while(scanf("%d %d", &N, &M) != EOF){
        bool ans = true;
        for(i = 0; i < N; i++){
            zeros[i] = 0;
            esq[i] = -1;
            for(j = 0; j < M; j++){
                scanf("%d", grid[i]+j);
                if(grid[i][j] == 0)
                    zeros[i]++;
                else{
                    if(esq[i] == -1)
                        esq[i] = j;
                    if(i > 0 && j <= esq[i-1])
                        ans = false;
                }
            }
            if(i > 0 && zeros[i-1] == M && zeros[i] != M)
                ans = false;
        }
        printf("%c\n", ans ? 'S' : 'N');
    }
    return 0;
}
