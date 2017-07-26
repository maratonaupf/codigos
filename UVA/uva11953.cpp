/*
 * Leonardo Deliyannis Constantin
 * UVa 11953 - Battleships
 */

#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
#define MAX 112

typedef pair<int, int> ii;

int N;
char grid[MAX][MAX];
bool vis[MAX][MAX];

const int di[] = { -1,  0, 0, 1 };  
const int dj[] = {  0, -1, 1, 0 };  

bool isValid(int i, int j){
	return 0 <= i && i < N && 0 <= j && j < N && grid[i][j] != '.';
}

bool ff(int si, int sj){
	bool alive = false;
	int i, j, k, i2, j2;
	vis[si][sj] = true;
	stack<ii> q;
	q.push(ii(si, sj));
	while(!q.empty()){
		i = q.top().first;
		j = q.top().second;
		q.pop();
		if(grid[i][j] == 'x') 
			alive = true;
		for(k = 0; k < 4; k++){
			i2 = i+di[k];
			j2 = j+dj[k];
			if(isValid(i2, j2) && !vis[i2][j2]){
				vis[i2][j2] = true;
				q.push(ii(i2, j2));
			}
		}
	}
	return alive;
}

int main(){
	int T, tc, i, j;
	scanf("%d\n", &T);
	for(tc = 1; tc <= T; tc++){
		scanf("%d\n", &N);
		for(i = 0; i < N; i++){
			fgets(grid[i], MAX, stdin);
			grid[i][N] = 0;
		}
		int ships = 0;
		memset(vis, false, sizeof(vis));
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				if(grid[i][j] != '.' && !vis[i][j] && ff(i, j)){
					ships++; }}}
		printf("Case %d: %d\n", tc, ships);
	}
	return 0;
}
