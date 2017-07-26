/*
 * Leonardo Deliyannis Constantin
 * UVa 12442 - Forwarding Emails
 */

#include <stdio.h>
#include <vector>
using namespace std;
#define INFTO 112345678

int N;
vector<int> LG;
vector<bool> vis;
vector<int> pd;

int dfs(int u){
	vis[u] = true;
	int ret = 0, w = LG[u];
	if(!vis[w]){
		ret += dfs(w) + 1;
	}
	vis[u] = false;
	return pd[u] = ret;
}

int main(){
	int T, u, w, i, tc;
	scanf("%d", &T);
	for(tc = 1; tc <= T; tc++){
		scanf("%d", &N);
		LG.assign(N+1, 0);
		vis.assign(N+1, false);
		pd.assign(N+1, -1);
		for(i = 0; i < N; i++){
			scanf("%d %d", &u, &w);
			LG[u] = w;
		}
		int ans = 0, val = 0;
		for(u = 1; u <= N; u++){
			if(pd[u] == -1) dfs(u);
			if(val < pd[u]){
				val = pd[u];
				ans = u;
			}
		}
		printf("Case %d: %d\n", tc, ans);
	}
	LG.clear();
	vis.clear();
	return 0;
}
