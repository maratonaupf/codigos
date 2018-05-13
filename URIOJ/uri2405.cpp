/*
 * Leonardo Deliyannis Constantin
 * URI 2405 - Colorindo
*/

#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define MAX 212

typedef pair<int, int> ii;
enum color {white, gray, black};

int n, m;
color grid[MAX][MAX];

const int di[] = {-1, -1, -1,  0, 0,  1, 1, 1};
const int dj[] = {-1,  0,  1, -1, 1, -1, 0, 1};

bool isValid(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < m;
}

int floodfill(int si, int sj){
    int ans = 0;
    grid[si][sj] = gray;
    queue<ii> Q;
    Q.push({si, sj});
    while(!Q.empty()){
        int i = Q.front().first, j = Q.front().second;
        Q.pop();
        ans++;
        for(int k = 0; k < 8; k++){
            int i2 = i+di[k], j2 = j+dj[k];
            if(isValid(i2, j2) && grid[i2][j2] == white){
                grid[i2][j2] = gray;
                Q.push({i2, j2});
            }
        }
    }
    return ans;
}

int main(){
    int x, y, k, i, j;
    while(scanf("%d %d %d %d %d", &n, &m, &x, &y, &k) != EOF){
        memset(grid, 0, sizeof(grid));
        while(k--){
            scanf("%d %d", &i, &j);
            i--, j--;
            grid[i][j] = black;
        }
        x--, y--;
        printf("%d\n", floodfill(x, y));
    }
    return 0;
}
