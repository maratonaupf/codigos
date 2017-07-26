/*
 * Leonardo Deliyannis Constantin
 * UVa 11094 - Continents
 */

#include <stdio.h>
#include <string.h>
#include <stack>
#include <cctype>
using namespace std;
#define MAX 22
#define LAND (grid[X][Y])

typedef pair<int, int> ii;

int M, N, X, Y;
char grid[MAX][MAX];
bool vis[MAX][MAX];

int di[] = { -1,  0,  0,  1 };
int dj[] = {  0, -1,  1,  0 };

bool isValid(int i){
	return 0 <= i && i < M;
}

int ff(int si, int sj){
	int i, j, k, i2, j2;
	int ret = 0;
	vis[si][sj] = true;
	stack<ii> q;
	q.push(ii(si, sj));
	while(!q.empty()){
		i = q.top().first;
		j = q.top().second;
		q.pop();
		ret++;
		for(k = 0; k < 4; k++){
			i2 = i+di[k];
			j2 = (j+dj[k]+N) % N;
			if(isValid(i2) && grid[i2][j2] == LAND && !vis[i2][j2]){
				vis[i2][j2] = true;
				q.push(ii(i2, j2));
			}
		}
	}
	return ret;
}

int main(){
	int i, j;
	while(scanf("%d %d\n", &M, &N) != EOF){
		for(i = 0; i < M; i++){
			fgets(grid[i], MAX, stdin);
			grid[i][N] = 0;
		}
		scanf("%d %d\n", &X, &Y);
		memset(vis, false, sizeof(vis));
		ff(X, Y);
		int ans = 0;
		for(i = 0; i < M; i++){
			for(j = 0; j < N; j++){
				if(grid[i][j] == LAND && !vis[i][j]){
					ans = max(ans, ff(i, j)); }}}
		printf("%d\n", ans);
	}
	return 0;
}
