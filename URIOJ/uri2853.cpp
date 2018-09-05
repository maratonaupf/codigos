/*
 * Leonardo Deliyannis Constantin
 * URI 2853 - Invenções de Bibika
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1123
#define INF 0x3f3f3f3f

typedef pair<int, int> ii;

int N, M;
char grid[MAX][MAX];
int dist[MAX][MAX];
const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

bool isValid(int i, int j){
    return 0 <= i && i < N && 0 <= j && j < M && grid[i][j] != '@';
}

void spread(int si, int sj){
    for(int k = 0; k < 4; k++){
        int i, j, cnt = 1;
        int i2 = si+di[k], j2 = sj+dj[k];
        for(i = i2, j = j2; isValid(i, j); i+=di[k], j+=dj[k], cnt++){
            dist[i][j] = min(dist[i][j], cnt);
        }
    }
}

int main(){
    int i, j, ans;
    while(scanf("%d %d", &N, &M) != EOF){
        memset(dist, INF, sizeof dist);
        vector<ii> v;
        for(i = 0; i < N; i++){
            scanf("%s", grid[i]);
            for(j = 0; j < M; j++){
                if(grid[i][j] == '@'){
                    dist[i][j] = 0;
                    v.push_back({i, j});
                }
            }
        }
        for(ii r : v)
            spread(r.first, r.second);
        ans = 0;
        for(i = 0; i < N; i++)
            for(j = 0; j < M; j++)
                ans = max(ans, dist[i][j]);
        printf("%d\n", ans != INF ? ans : -1);
    }
    return 0;
}
