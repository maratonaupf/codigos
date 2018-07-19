/*
 * Leonardo Deliyannis Constantin
 * URI 2317 - Lobo Mau
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
#define MAX 252

typedef pair<int, int> ii;

int R, C;
char grid[MAX][MAX];
bool vis[MAX][MAX];

const int di[] = {-1,  0,  0,  1};
const int dj[] = { 0, -1,  1,  0};

bool isValid(int i, int j){
    return 0 <= i && i < R && 0 <= j && j < C && grid[i][j] != '#';
}

int floodfill(int si, int sj){
    int sheep = 0, wolves = 0;
    vis[si][sj] = true;
    queue<ii> Q;
    Q.push({si, sj});
    while(!Q.empty()){
        int i = Q.front().first, j = Q.front().second;
        if(grid[i][j] == 'k') sheep++;
        if(grid[i][j] == 'v') wolves++;
        Q.pop();
        for(int k = 0; k < 4; k++){
            int i2 = i+di[k], j2 = j+dj[k];
            if(!isValid(i2, j2)) continue;
            if(!vis[i2][j2]){
                vis[i2][j2] = true;
                Q.push({i2, j2});
            }
        }
    }
    return sheep > wolves ? sheep : -wolves;
}

int main(){
    int i, j, sheep, wolves;
    while(scanf("%d %d ", &R, &C) != EOF){
        for(i = 0; i < R; i++){
            fgets(grid[i], MAX, stdin);
        }
        sheep = wolves = 0;
        memset(vis, 0, sizeof(vis));
        for(i = 0; i < R; i++){
            for(j = 0; j < C; j++){
                if(grid[i][j] != '#' && !vis[i][j]){
                    int ans = floodfill(i, j);
                    sheep  += max( ans, 0);
                    wolves += max(-ans, 0);
                }
            }
        }
        printf("%d %d\n", sheep, wolves);
    }
    return 0;
}
