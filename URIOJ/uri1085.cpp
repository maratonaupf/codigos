/*
 * Leonardo Deliyannis Constantin
 * URI 1085 - Babel
 */

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
#define LEN 112
#define INFTO ((int)1e9)

typedef pair<string, string> ss;
typedef pair<int, ss> iss;

int M;
map<string, vector<ss> > LG;
map<string, int> dist;

int dijkstra(string s, string t){
	string u, v, w, x;
	dist[s] = 0;
	priority_queue<iss, vector<iss>, greater<iss> > Q;
	Q.push(iss(0, ss(s, " ")));
	while(!Q.empty()){
		u = Q.top().second.first; 
		x = Q.top().second.second; 
		Q.pop();
		if(u == t) break;
		for(int i = 0; i < (int)LG[u].size(); i++){
			v = LG[u][i].first;
			w = LG[u][i].second;
			if(w[0] != x[0]
			&& dist[v] > dist[u] + (int)w.size()){
				dist[v] = dist[u] + (int)w.size();
				Q.push(iss(dist[v], ss(v, w)));
			}
		}
	}
	return dist[t];
}

int main(){
	char O[LEN], D[LEN];
	char u[LEN], v[LEN], w[LEN];
	while(scanf("%d", &M), M != 0){
		scanf("%s %s", O, D);
		LG.clear();
		dist.clear();
		dist[O] = dist[D] = INFTO;
		for(int i = 0; i < M; i++){
			scanf("%s %s %s", u, v, w);
			dist[u] = dist[v] = INFTO;
			LG[u].push_back(ss(v, w));
			LG[v].push_back(ss(u, w));
		}
		int ans = dijkstra(D, O);
		if(ans == INFTO) printf("impossivel\n");
		else printf("%d\n", ans);
	}
	return 0;
}
