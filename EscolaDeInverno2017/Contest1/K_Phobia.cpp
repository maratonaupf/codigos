/*
 * Leonardo Deliyannis Constantin
 * K - Phobia
 */

#include <stdio.h>
#include <queue>
using namespace std;
#define INFTO ((int)1e9)
#define MAX 112

typedef pair<int, int> ii;

int N, M;
char grid[MAX][MAX];
int bugs[MAX][MAX];
int sally[MAX][MAX];

const int di[] = {-1,  0, 0, 1};
const int dj[] = { 0, -1, 1, 0};

void resetDist(int dist[MAX][MAX]){
	int i, j;
	for(i = 0; i < N; i++)
		for(j = 0; j < M; j++)
			dist[i][j] = INFTO;
}

bool isValid(int i, int j){
	return 0 <= i && i < N && 0 <= j && j < M && grid[i][j] != '#';
}

void bfs(int si, int sj, int dist[MAX][MAX]){
	int i, j, k, i2, j2;
	dist[si][sj] = 0;
	queue<ii> Q;
	Q.push(ii(si, sj));
	while(!Q.empty()){
		i = Q.front().first;
		j = Q.front().second;
		Q.pop();
		for(k = 0; k < 4; k++){
			i2 = i+di[k];
			j2 = j+dj[k];
			if(isValid(i2, j2) && dist[i2][j2] > dist[i][j] + 1){
				dist[i2][j2] = (grid[i2][j2] == '*') ? 0 : dist[i][j] + 1;
				Q.push(ii(i2, j2));
			}
		}
	}
}

int main(){
	int T, i, j, xi, xj;
	scanf("%d\n", &T);
	while(scanf("%d %d\n", &N, &M) != EOF){
		for(i = 0; i < N; i++){
			fgets(grid[i], MAX, stdin);
			grid[i][M] = 0;
		}
		resetDist(bugs);
		resetDist(sally);
		xi = xj = -1;
		for(i = 0; i < N; i++){
			for(j = 0; j < M; j++){
				if(grid[i][j] == '*' && bugs[i][j] != 0){
					bfs(i, j, bugs);
				}
				if(grid[i][j] == 'S'){
					bfs(i, j, sally);
				}
				if(grid[i][j] == 'X'){
					xi = i; xj = j;
				}
			}
		}
		printf("%s\n", sally[xi][xj] < bugs[xi][xj] ? "yes" : "no");
	}
	return 0;
}
