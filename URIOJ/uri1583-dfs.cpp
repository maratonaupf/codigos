/*
 * Leonardo Deliyannis Constantin
 * URI 1583 - Contaminação
*/

#include <stdio.h>
#include <string.h>
#define MAX 52

int N, M;
char grid[MAX][MAX];
bool vis[MAX][MAX];
const int di[] = {-1,  0,  0,  1};
const int dj[] = { 0, -1,  1,  0};

bool isValid(int i, int j){
    return 0 <= i && i < N && 0 <= j && j < M;
}

void floodfill(int i, int j){
    if(!isValid(i, j) || grid[i][j] == 'X' || vis[i][j])
        return;
    vis[i][j] = true;
    grid[i][j] = 'T';
    for(int k = 0; k < 4; k++)
        floodfill(i+di[k], j+dj[k]);
}

int main(){
    int i, j;
    while(scanf("%d %d", &N, &M) != EOF && (N || M)){
        for(i = 0; i < N; i++)
            if(M) scanf(" %s", grid[i]);
        memset(vis, 0, sizeof(vis));
        for(i = 0; i < N; i++)
            for(j = 0; j < M; j++)
                if(grid[i][j] == 'T')
                    floodfill(i, j);
        for(i = 0; i < N; i++)
            if(M) printf("%s\n", grid[i]);
        printf("\n");
    }
    return 0;
}
