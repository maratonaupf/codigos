/*
 * Leonardo Deliyannis Constantin
 * https://open.kattis.com/problems/prva
*/

#include <stdio.h>
#include <string.h>
#define MAX 23

int N, M;
char grid[MAX][MAX];

int main(){
    int i, j, noAns, tam;
    char tmp[MAX], ans[MAX];
    while(scanf(" %d %d ", &N, &M) != EOF){
        for(i = 0; i < N; i++){
            fgets(grid[i], MAX, stdin);
            grid[i][M] = '#';
        }
        for(j = 0; j <= M; j++){
            grid[N][j] = '#';
        }
        noAns = 1;
        tam = 0;
        for(i = 0; i < N; i++){
            for(j = 0; j <= M; j++){
                if(grid[i][j] == '#'){
                    tmp[tam] = '\0';
                    if((noAns || strcmp(tmp, ans) < 0) && tam >= 2){
                        strcpy(ans, tmp);
                        noAns = 0;
                    }
                    tam = 0;
                }
                else
                    tmp[tam++] = grid[i][j];
            }
        }
        for(j = 0; j < M; j++){
            for(i = 0; i <= N; i++){
                if(grid[i][j] == '#'){
                    tmp[tam] = '\0';
                    if((noAns || strcmp(tmp, ans) < 0) && tam >= 2){
                        strcpy(ans, tmp);
                        noAns = 0;
                    }
                    tam = 0;
                }
                else
                    tmp[tam++] = grid[i][j];
            }
        }
        printf("%s\n", ans);
    }
    return 0;
}
