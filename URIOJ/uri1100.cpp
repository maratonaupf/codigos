/*
 * Leonardo Deliyannis Constantin
 * URI 1100 - Movimentos do Cavalo
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <queue>
using namespace std;
#define MAX 8
#define INFTO ((int)1e9)
#define fst first
#define snd second

typedef pair<int, int> ii;

int dist[MAX][MAX];
int di[] = {-2, -2, -1, -1,  1,  1,  2,  2};
int dj[] = {-1,  1, -2,  2, -2,  2, -1,  1};

inline bool isValid(int i, int j){
    return 0 <= i && i < 8 && 0 <= j && j < 8;
}

int bfs(int si, int sj, int ti, int tj){
    int i, j, k, i2, j2;
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            dist[i][j] = INFTO; }}
    dist[si][sj] = 0;
    queue<ii> Q;
    Q.push(ii(si, sj));
    while(!Q.empty()){
        i = Q.front().fst;
        j = Q.front().snd;
        Q.pop();
        for(k = 0; k < 8; k++){
            i2 = i+di[k];
            j2 = j+dj[k];
            if(isValid(i2, j2) 
            && dist[i2][j2] > dist[i][j] + 1){
                dist[i2][j2] = dist[i][j] + 1;
                Q.push(ii(i2, j2));
            }
        }
    }
    return dist[ti][tj];
}

int main(){
    int si, sj, ti, tj;
    char a[4], b[4];
    while(scanf("%s %s", a, b) != EOF){
        si = a[0] - 'a';
        sj = a[1] - '1';
        ti = b[0] - 'a';
        tj = b[1] - '1';
        printf("To get from %s to %s takes %d "
            "knight moves.\n", a, b, bfs(si, sj, ti, tj));
    }
    return 0;
}
