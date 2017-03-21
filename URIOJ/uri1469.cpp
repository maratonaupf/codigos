#include<stdio.h>
#include<string.h>
#include<bitset>
#include<stack>
#include<algorithm>
#define MAX 512
#define DEBP

using namespace std;

int N, M, I;
int id[MAX];
int LG[MAX][MAX];
int d[MAX];
int pos[MAX];
bitset<MAX> vis;

int youngestBoss(int s){
	if(d[pos[s]] == 0) return -1;
	int u, i, w, resp = -1;
	vis.reset(); 
	vis[pos[s]] = true;
	stack<int> st;
	st.push(pos[s]);
	while(!st.empty()){
		u = st.top(); st.pop();
		if(u != pos[s]){
			if(resp == -1) resp = u;
			else if(id[u] < id[resp]) resp = u;
		}
	
		for(i = 0; i < d[u]; i++){
			w = LG[u][i];
			if(!vis[w]){
				vis[w] = true;
				st.push(w);
			}
		}
	}
	return resp;
}

void swapEmployees(int x, int y){
	swap(id[pos[x]], id[pos[y]]);
	swap(pos[x], pos[y]);
}

int main(void){
	int i, x, y, com, resp;
	while(scanf("%d %d %d\n", &N, &M, &I) != EOF){
		for(i = 1; i <= N; i++){
			scanf("%d", id+i);
			pos[i] = i;
		}
		memset(d, 0, sizeof(d));
		for(i = 1; i <= M; i++){
			scanf("%d %d\n", &x, &y);
			LG[y][d[y]++] = x;
		}
		while(I--){
			com = getchar();
			switch(com){
				case 'P': 
					scanf("%d\n", &x);
					resp = youngestBoss(x);
					(resp != -1) ? printf("%d\n", id[resp]) : printf("*\n");
				break;
				case 'T':
					scanf("%d %d\n", &x, &y);
					swapEmployees(x, y);
				break;
			}
		}
	}
	return 0;
}
