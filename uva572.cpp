/*
 * Leonardo Deliyannis Constantin
 * UVa 572
 */

#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;
const int MAX = 112;

typedef pair<int, int> ii;
typedef vector<bool> vb;

int M, N;
char grid[MAX][MAX];
const int di[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
const int dj[] = { -1,  0,  1, -1, 1, -1, 0, 1 };
vector<vb> vis;

bool isValid(int i, int j){
	return 0 <= i && i < M && 0 <= j && j < N;
}

void dfs(int si, int sj){
	int i, j, k, i2, j2;
	vis[si][sj] = true;
	stack<ii> S;
	S.push(ii(si, sj));
	while(!S.empty()){
		i = S.top().first;
		j = S.top().second;
		S.pop();
		for(k = 0; k < 8; k++){
			i2 = i + di[k];
			j2 = j + dj[k];
			if(isValid(i2, j2) && !vis[i2][j2] 
			&& grid[i2][j2] == '@'){
				vis[i2][j2] = true;
				S.push(ii(i2, j2));
			}
		}
	}
}

int main(){
	int i, j, ncomp;
	while(scanf("%d %d\n", &M, &N), M != 0){
		for(i = 0; i < M; i++){
			fgets(grid[i], MAX, stdin);
			grid[i][N] = 0;
		}
		vis.assign(M, vb(N, false));
		ncomp = 0;
		for(i = 0; i < M; i++){
			for(j = 0; j < N; j++){
				if(grid[i][j] == '@' && !vis[i][j]){
					dfs(i, j);
					ncomp++;
				}
			}
		}
		printf("%d\n", ncomp);
	}
	return 0;
}
