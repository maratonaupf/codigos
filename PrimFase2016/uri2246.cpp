#include<stdio.h>
#include<string.h>
#include<stack>
#include<utility>
#include<algorithm>
using namespace std;
#define MAX 212
/* fine INFTO 1123456789 */
#define INFTO 1000000000

int R, C;
int grid[MAX][MAX];
bool vis[MAX][MAX];

typedef pair<int, int> ii;

int dfs(int si, int sj){
	const int di[] = {-1, 0, 0, 1};
	const int dj[] = {0, -1, 1, 0};
	int ret = 0, i, j, k, i2, j2;
	stack<ii> st;
	st.push(ii(si, sj));
	vis[si][sj] = 1;
	while(!st.empty()){
		i = st.top().first;
		j = st.top().second;
		st.pop();
		ret++;
		for(k = 0; k < 4; k++){
			i2 = i+di[k];
			j2 = j+dj[k];
			/* testing if positions are valid within the grid */
			if(0 <= i2 && i2 < R && 0 <= j2 && j2 < C &&  
				!vis[i2][j2] && grid[i2][j2] == grid[si][sj]){
				vis[i2][j2] = 1;
				st.push(ii(i2, j2));
			}
		}
	}
	return ret;
}

int main(void){
	int i, j;
	while(scanf("%d %d", &R, &C) != EOF){
		for(i = 0; i < R; i++)
			for(j = 0; j < C; j++)
				scanf("%d", grid[i]+j);
		
		memset(vis, 0, sizeof(vis));
		int menor = INFTO;
		for(i = 0; i < R; i++){
			for(j = 0; j < C; j++){
				if(!vis[i][j]){
					menor = min(menor, dfs(i, j));
				}
			}
		}
		printf("%d\n", menor);
	}
	return 0;
}
