/*
 * Leonardo Deliyannis Constantin
 * UVa 10653 - Bombs! NO they are Mines!!
 */

#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define MAX 1123
#define INFTO 112345678

typedef pair<int, int> ii;

int R, C;
char grid[MAX][MAX];
int dist[MAX][MAX];

const int di[] = {-1, 0, 0, 1};
const int dj[] = { 0,-1, 1, 0};

bool isValid(int i, int j){
	return 0 <= i && i < R && 0 <= j && j < C && grid[i][j] != '*';
}

int bfs(int si, int sj, int ti, int tj){
	int i, j, k, i2, j2;
	for(i = 0; i < R; i++){
		for(j = 0; j < C; j++){
			dist[i][j] = INFTO; }}
	dist[si][sj] = 0;
	queue<ii> q;
	q.push(ii(si, sj));
	while(!q.empty()){
		i = q.front().first;
		j = q.front().second;
		q.pop();
		if(i == ti && j == tj) break;
		for(k = 0; k < 4; k++){
			i2 = i+di[k];
			j2 = j+dj[k];
			if(isValid(i2, j2) && dist[i2][j2] == INFTO){
				dist[i2][j2] = dist[i][j] + 1;
				q.push(ii(i2, j2));
			}
		}
	}
	return dist[ti][tj];
}

int main(){
	int rows, cols, i, j;
	int si, sj, ti, tj;
	while(scanf("%d %d", &R, &C), R != 0){
		memset(grid, '.', sizeof(grid));
		scanf("%d", &rows);
		while(rows--){
			scanf("%d %d", &i, &cols);
			while(cols--){
				scanf("%d", &j);
				grid[i][j] = '*';
			}
		}
		scanf("%d %d", &si, &sj);
		scanf("%d %d", &ti, &tj);
		printf("%d\n", bfs(si, sj, ti, tj));
	}
	return 0;
}
