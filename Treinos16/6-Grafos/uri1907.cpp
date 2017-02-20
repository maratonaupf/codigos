#include<stdio.h>
#include<string.h>
#include<stack>
#include<bitset>
#define MAX 1123456

using namespace std;

int N, M;
int LG[MAX][4];
int d[MAX];
bitset<MAX> vis;

int dfs(int s){
	int u, i, w, ret = 0;
	vis[s] = true;
	stack<int> st;
	st.push(s);
	while(!st.empty()){
		u = st.top(); st.pop();
		for(i = 0; i < d[u]; i++){
			w = LG[u][i];
			if(!vis[w]){
				vis[w] = true;
				st.push(w);
			}
		}
	}
	return ret;
}

int main(void){
	int u, resp;
	char v[MAX];
	while(scanf("%d %d", &N, &M) != EOF){
		for(u = 0; u < N*M; u++){
			if(u % M == 0) getchar();
			v[u] = getchar();
		}
		memset(d, 0, sizeof(d));
		vis.reset();
		for(u = 0; u < N*M; u++){
			if(v[u] == '.'){
				if(u-M >= 0 && v[u-M] == '.') LG[u][d[u]++] = u-M;
				if(u%M != 0 && v[u-1] == '.') LG[u][d[u]++] = u-1;
				if((u+1)%M != 0 && v[u+1] == '.') LG[u][d[u]++] = u+1;
				if(u+M < N*M && v[u+M] == '.') LG[u][d[u]++] = u+M;
			}
			else vis[u] = true;
		}
		resp = 0;
		for(u = 0; u < N*M; u++){
			if(!vis[u]){
				dfs(u); resp++;
			}
		}
		printf("%d\n", resp);
	}
	return 0;
}
