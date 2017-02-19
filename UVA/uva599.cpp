#include<stdio.h>
#include<string.h>
#include<queue>
#define LEN 53
#define MAX 26
using namespace std;

int N;
int LG[MAX][MAX];
int d[MAX];
bool vis[MAX];

bool bfs(int s){
	int u, w, i;
	vis[s] = true;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		u = q.front(); q.pop();
		for(i = 0; i < d[u]; i++){
			w = LG[u][i];
			if(!vis[w]){
				vis[w] = true;
				q.push(w);
			}
		}
	}
	return d[s] > 0;
}

int main(void){
	int T, u, w, i;
	int trees, acorns;
	char s[LEN];
	scanf("%d\n", &T);
	while(T--){
		memset(d, 0, sizeof(d));
		while(fgets(s, LEN, stdin), s[0] != '*'){
			u = s[1] - 'A';
			w = s[3] - 'A';
			LG[u][d[u]++] = w;
			LG[w][d[w]++] = u;
		}
		fgets(s, LEN, stdin);
		trees = acorns = 0;
		memset(vis, 0, sizeof(vis));
		for(i = 0; 'A' <= s[i] && s[i] <= 'Z'; i+=2){
			u = s[i] - 'A';
			if(!vis[u]) bfs(u) ? trees++ : acorns++;
		}
		printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
	}
	return 0;
}
