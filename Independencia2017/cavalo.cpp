/*
 * Leonardo Deliyannis Constantin
 * cavalo
 */

#include <stdio.h>
#include <queue>
using namespace std;
#define MAX 11
#define INFTO ((int)1e9)

typedef pair<int, int> ii;

const int N = 8;
char grid[MAX][MAX];
const int di[] = { -2, -2, -1, -1,  1, 1,  2, 2 };
const int dj[] = { -1,  1, -2,  2, -2, 2, -1, 1 };
int dist[MAX][MAX];

bool isValid(int i, int j){
	return 0 <= i && i < N && 0 <= j && j < N && grid[i][j] != 'X';
}

int bfs(int si, int sj, int ti, int tj){
	int i, j, k, i2, j2;
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			dist[i][j] = INFTO;
	dist[si][sj] = 0;
	queue<ii> Q;
	Q.push(ii(si, sj));
	while(!Q.empty()){
		i = Q.front().first;
		j = Q.front().second;
		Q.pop();
		for(k = 0; k < 8; k++){
			i2 = i+di[k];
			j2 = j+dj[k];
			if(isValid(i2, j2) && 
				dist[i2][j2] > dist[i][j] + 1){
				dist[i2][j2] = dist[i][j] + 1;
				Q.push(ii(i2, j2));
			}
		}
	}
	return dist[ti][tj];
}

int main(){
	int i, j, ans;
	int si, sj, ti, tj;
	while(fgets(grid[0], MAX, stdin) != NULL){
		for(i = 1; i < N; i++){
			fgets(grid[i], MAX, stdin);
		}
		si = sj = ti = tj = -1;
		for(i = 0; i < N; i++){
			grid[i][N] = 0;
			for(j = 0; j < N; j++){
				if(grid[i][j] == 'I'){
					si = i; sj = j;
				}
				if(grid[i][j] == 'F'){
					ti = i; tj = j;
				}
			}
		}
		ans = bfs(si, sj, ti, tj);
		if(ans != INFTO)
			printf("Numero minino de movimentos: %d\n", ans);
		else printf("Impossivel ir de I a F\n");
	}
	return 0;
}
