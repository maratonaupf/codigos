/*
 * Leonardo Deliyannis Constantin
 * F - Tesouro
 */

#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;

typedef vector<int> vi;

int N;
vector<set<int> > LG;
vector<int> q, b, ts, inc;

inline void topoSort(){
	ts.clear();
	priority_queue<int, vector<int>, greater<int> > Q;
	for(int i = 0; i <= N + 1; ++i){
		if(inc[i] == 0){
			Q.push(i); }}
	while(!Q.empty()){
		int u = Q.top(); Q.pop();
		ts.push_back(u);
		for(int w : LG[u]){
			if(--inc[w] == 0){
				Q.push(w);
			}
		}
	}
}

inline void addEdge(int u, int w){
	LG[u].insert(w);
	inc[w]++;
}

bool hasEdge(int u, int w){
	return LG[u].find(w) != LG[u].end();
}

int pd(int i){
	if(b[i] != -1) return b[i];
	if(i == 0) return b[i] = 0;
	int ret = 0;
	for(int k = 0; k < (int)ts.size() && ts[k] != i; k++){
		if(hasEdge(ts[k], i)){
			ret = max(pd(ts[k]) + q[i], ret);
		}
	}
	return b[i] = ret;
}

int main(){
	int p, u, w;
	while(scanf("%d", &N), N != 0){
		LG.assign(N+2, set<int>());
		q.assign(N+2, 0);
		inc.assign(N+2, 0);
		for(u = 1; u <= N; u++){
			scanf("%d %d", &q[u], &p);
			while(p--){
				scanf("%d", &w);
				addEdge(u, w);
			}
			addEdge(0, u);
			addEdge(u, N+1);
		}
		topoSort();
		b.assign(N+2, -1);
		printf("%d\n", pd(N+1));
	}
	return 0;
}
