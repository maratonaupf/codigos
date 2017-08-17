#include<stdio.h>
#include<map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define MAX 100005
#define INFTO 112345678
#define pb push_back

typedef pair<int, int> edge;
typedef vector<int> vi;

int N, E;
vector<vi> LG;
vector<edge> els;

int i, o[MAX], c[MAX], pai[MAX], r, fr;
bool art[MAX];
map<edge, bool> br;

void hpt2(int u);

void hpt(){
	i = 1;
	for(int u = 1; u <= N; u++){
		o[u] = c[u] = 0; art[u] = false;
	}
	for(edge e: els)
		br[e] = br[edge(e.second, e.first)] = false;
	for(int s = 1; s <= N; s++){
		if(o[s] == 0){
			r = s; fr = 0; pai[r] = r;
			hpt2(r);
			if(fr > 1) art[r] = true;
		}
	}
}

void hpt2(int u){
	o[u] = c[u] = i; i++;
	for(int w : LG[u]){
		if(o[w] == 0){
			pai[w] = u;
			if(u == r) fr++;
			hpt2(w);
			if(c[w] >= o[u])
				br[edge(u, w)] = br[edge(w, u)] = true;
			c[u] = min(c[u], c[w]);
		}
		else if(w != pai[u]){
			c[u] = min(c[u], c[w]);
		}
	}
}

int pontes(int s, int t){
	int u, ret = 0;
	vector<bool> vis(N+1, false);
	
	queue<int> Q;
	Q.push(s);
	while(!Q.empty()){
		u = Q.front(); Q.pop();
		for(int w : LG[u]){
			if(br[edge(u, w)]) ret++;
			if(!vis[w]){
				vis[w] = true;
				Q.push(w);
			}
		}
	}
	return ret;
}

int main(){
	int T, t;
	int Q, j, u, w;
	scanf("%d", &T);
	for(t = 1; t <= T; ++t){
		scanf("%d %d", &N, &E);
		for(j = 0; j < E; j++){
			scanf("%d %d", &u, &w);
			LG[u].pb(w);
			LG[w].pb(u);
			els.pb(edge(u, w));
		}
		hpt();
		scanf("%d", &Q);
		printf("Case %d:\n", t);
		while(Q--){
			printf("%d\n", pontes(u, w));
		}
		LG.clear();
		els.clear();
	}
	return 0;
}
