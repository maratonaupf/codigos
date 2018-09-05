/*
 * Leonardo Deliyannis Constantin
 * URI 1583 - Contaminação
*/

#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define MAX 52

typedef pair<int, int> ii;

int N, M;
char grid[MAX][MAX];
bool vis[MAX][MAX];
const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

bool isValid(int i, int j){
    return 0 <= i && i < N && 0 <= j && j < M;
}

void floodfill(int si, int sj){
    vis[si][sj] = true;
    queue<ii> q;
    q.push({si, sj});
    while(!q.empty()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        grid[i][j] = 'T';
        for(int k = 0; k < 4; k++){
            int i2 = i+di[k], j2 = j+dj[k];
            if(!isValid(i2, j2) || grid[i2][j2] == 'X') continue;
            if(!vis[i2][j2] && grid[i2][j2] == 'A'){
                vis[i2][j2] = true;
                q.push({i2, j2});
            }
        }
    }
}

int main(){
    int i, j;
    while(scanf("%d %d", &N, &M), N){
        for(i = 0; i < N; i++)
            scanf("%s", grid[i]);
        memset(vis, 0, sizeof vis);
        for(i = 0; i < N; i++)
            for(j = 0; j < M; j++)
                if(grid[i][j] == 'T' && !vis[i][j])
                    floodfill(i, j);
        for(i = 0; i < N; i++)
            printf("%s\n", grid[i]);
        printf("\n");
    }
    return 0;
}
