/*
 * Leonardo Deliyannis Constantin
 * URI 2485 - Bicho da Goiaba
*/

#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 112
#define INFTO 0x3f3f3f3f

typedef pair<int, int> ii;

int A, B;
int grid[MAX][MAX];
int dist[MAX][MAX];

const int di[] = { -1, -1, -1,  0,  0,  1,  1,  1 };
const int dj[] = { -1,  0,  1, -1,  1, -1,  0,  1 };

bool isValid(int i, int j){
    return 0 <= i && i < A && 0 <= j && j < B && grid[i][j] == 1;
}

int bfs(int si, int sj){
    int ans = 0;
    memset(dist, INFTO, sizeof(dist));
    dist[si][sj] = 0;
    queue<ii> Q;
    Q.push({si, sj});
    while(!Q.empty()){
        int i = Q.front().first, j = Q.front().second;
        Q.pop();
        ans = max(ans, dist[i][j]);
        for(int k = 0; k < 8; k++){
            int i2 = i+di[k], j2 = j+dj[k];
            if(!isValid(i2, j2)) continue;
            if(dist[i2][j2] > dist[i][j] + 1){
                dist[i2][j2] = dist[i][j] + 1;
                Q.push({i2, j2});
            }
        }
    }
    return ans;
}

int main(){
    int T, i, j, x, y;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &A, &B);
        for(i = 0; i < A; i++)
            for(j = 0; j < B; j++)
                scanf("%d", grid[i]+j);
        scanf("%d %d", &x, &y);
        printf("%d\n", bfs(x-1, y-1));
    }
    return 0;
}
