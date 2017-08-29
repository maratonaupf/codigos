/*
 * Leonardo Deliyannis Constantin
 * Maratona SBC 2016 - Ladrilhos
*/

#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define INFTO ((int)1e9);

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;

int H, L;
vector<vi> grid;
vector<vb> vis;

const int di[] = { -1,  0, 0, 1 };
const int dj[] = {  0, -1, 1, 0 };

bool isValid(int i, int j){
	return 0 <= i && i < H && 0 <= j && j < L;
}

int dfs(int si, int sj){
	int i, j, k, i2, j2, ret = 0;
	vis[si][sj] = true;
	stack<ii> S;
	S.push(ii(si, sj));
	while(!S.empty()){
		i = S.top().first;
		j = S.top().second;
		S.pop();
		ret++;
		for(k = 0; k < 4; k++){
			i2 = i+di[k];
			j2 = j+dj[k];
			if(isValid(i2, j2) && !vis[i2][j2] 
			&& grid[i][j] == grid[i2][j2]){
				vis[i2][j2] = true;
				S.push(ii(i2, j2));
			}
		}
	}
	return ret;
}

int main(){
	int i, j, ans;
	while(scanf("%d %d", &H, &L) != EOF){
		grid.assign(H, vi(L, 0));
		for(i = 0; i < H; i++){
			for(j = 0; j < L; j++){
				scanf("%d", &grid[i][j]);
			}
		}
		vis.assign(H, vb(L, false));
		ans = INFTO;
		for(i = 0; i < H; i++)
			for(j = 0; j < L; j++)
				if(!vis[i][j])
					ans = min(ans, dfs(i, j));
		printf("%d\n", ans);
	}
	return 0;
}
