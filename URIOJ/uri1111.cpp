/*
 * Leonardo Deliyannis Constantin
 * URI 1111 - Desrugenstein
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 11
#define INF 0x3c3c3c3c

int N;
int dist[MAX][MAX][MAX][MAX];
bool vis[MAX][MAX];
const int dy[] = {1, -1,  0, 0};
const int dj[] = {0,  0, -1, 1};

bool isValid(int y, int x){
    return 0 <= y && y < N && 0 <= x && x < N;
}

void floydWarshall(){
    int y3, x3, y, x, y2, x2;
    for(y3 = 0; y3 < N; y3++)
        for(x3 = 0; x3 < N; x3++)
            for(y = 0; y < N; y++)
                for(x = 0; x < N; x++)
                    for(y2 = 0; y2 < N; y2++)
                        for(x2 = 0; x2 < N; x2++)
                            dist[y][x][y2][x2] = min(dist[y][x][y2][x2],
                                dist[y][x][y3][x3] + dist[y3][x3][y2][x2]);
}

int main(){
    int P, cost;
    int y, x, k, y2, x2, ans;
    while(scanf("%d", &N), N){
        memset(dist, INF, sizeof(dist));
        for(y = N-1; y >= 0; y--){
            for(x = 0; x < N; x++){
                dist[y][x][y][x] = 0;
                for(k = 0; k < 4; k++){
                    scanf("%d", &cost);
                    y2 = y+dy[k], x2 = x+dj[k];
                    if(cost && isValid(y2, x2)){
                        dist[y][x][y2][x2] = 1;
                    }
                }
            }
        }
        floydWarshall();
        scanf("%d", &P);
        while(P--){
            scanf("%d %d %d %d", &x, &y, &x2, &y2);
            ans = dist[y][x][y2][x2];
            if(ans < INF)
                printf("%d\n", ans);
            else
                printf("Impossible\n");
        }
        printf("\n");
    }
    return 0;
}
