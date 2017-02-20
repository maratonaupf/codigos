#include<stdio.h>
#include<string.h>
#include<queue>
#include<bitset>
#include<set>
#define MAX 112345
#define INFTO 1123456789

using namespace std;

set<int> ch;
int LG[MAX][6];
int d[MAX];
bitset<MAX> viz;

bool isValid(int u){
	const int DEZ_5 = 100000;
	return (!ch.count(u) && 0 < u && u <= DEZ_5);
}

void addViz(int u, int w){
	if(isValid(w)) LG[u][d[u]++] = w;
}

void buildviz(int u){
	if(viz[u]) return;
	if(isValid(u)){
		if(!(u&1)) addViz(u, u/2);
		addViz(u, u-1);
		addViz(u, u+1);
		addViz(u, u*2);
		addViz(u, u*3);
	}
	viz[u] = true;
}

int bfs(int s, int t){
	viz.reset();
	int i, u, w, dist[MAX];
	memset(dist, -1, sizeof(dist));
	memset(d, 0, sizeof(d));
	dist[s] = 0;
	queue<int> st;
	st.push(s);
	while(!st.empty()){
		u = st.front(); st.pop();
		if(u == t) return dist[t];
		buildviz(u);
		for(i = 0; i < d[u]; i++){
			w = LG[u][i];
			if(dist[w] == -1){
				dist[w] = dist[u] + 1;
				st.push(w);
			}
			if(w == t) return dist[w];
		}
	}
	return -1;
}

int main(void){
	int O, D, K, aux;
	while(scanf("%d %d %d", &O, &D, &K), O){
		while(K--){
			scanf("%d", &aux);
			ch.insert(aux);
		}
		printf("%d\n", bfs(O, D));
		ch.clear();
	}
	return 0;
}
