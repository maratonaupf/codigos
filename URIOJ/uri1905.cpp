#include<stdio.h>
#include<string.h>
#include<queue>
#include<assert.h>
#define MAX 25
//#define DEBP

using namespace std;

int LG[MAX][4];
int d[MAX];
bool vis[MAX];

bool bfs(int s, int t){
	int u, i, w;
	memset(vis, 0, sizeof(vis));
	vis[s] = true;
	
	queue<int> q;
	q.push(s);
	
	while(!q.empty()){
		u = q.front(); q.pop();
		if(u == t) return true;
		
		for(i = 0; i < d[u]; i++){
			w = LG[u][i];
			if(w == t) return true;
			if(!vis[w]){
				vis[w] = true;
				q.push(w);
			}
		}	
	}
	return false;
}

#ifdef DEBP
void printAdjList(){
	for(int i = 0; i < 25; i++){
		printf("LG[%d]:", i);
		for(int j = 0; j < d[i]; j++){
			printf(" %d", LG[i][j]);
		}
		printf("\n");
	}
}
#endif

int main(void){
	int T, u, v[MAX];
	scanf("%d", &T);
	while(T--){
		getchar();
		memset(d, 0, sizeof(d));
		for(u = 0; u < MAX; u++) scanf("%d", v+u);
		for(u = 0; u < MAX; u++){
			if(u-5 >= 0 && v[u-5] == 0)
				LG[u][d[u]++] = u-5;
				
			if(u%5 != 0 && v[u-1] == 0)
				LG[u][d[u]++] = u-1;
				
			if((u+1)%5 != 0 && v[u+1] == 0)
				LG[u][d[u]++] = u+1;
				
			if(u+5 < MAX && v[u+5] == 0)
				LG[u][d[u]++] = u+5;
		}
		puts(bfs(24, 0) ? "COPS" : "ROBBERS");
	}
	return 0;
}
