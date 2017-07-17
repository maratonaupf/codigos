/*
 * Leonardo Deliyannis Constantin
 * UVa 11060 - Beverages
 */

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
#define LEN 52

typedef vector<int> vi;
typedef vector<string> vs;
typedef unordered_map<string, vs> graph;
typedef unordered_map<string, int> msi;

vs kahn(const vs &ls, graph &adj, msi &inc, msi &idx){
	vs ts;
	priority_queue<int, vi, greater<int> > Q;
	for(auto it = ls.begin(); it != ls.end(); ++it){
		if(inc[*it] == 0){
			Q.push(idx[*it]); }}
	while(!Q.empty()){
		string u = ls[Q.top()]; Q.pop();
		ts.push_back(u);
		for(auto it = adj[u].begin(); it != adj[u].end(); ++it){
			string w = *it;
			if(--inc[w] == 0){
				Q.push(idx[w]);
			}
		}
	}
	return ts;
}

int main(){
	int V, E, i, T = 0;
	char u[LEN], w[LEN];
	while(scanf("%d\n", &V) != EOF){
		graph adj;
		msi inc, idx;
		vs ls;
		for(i = 0; i < V; i++){
			scanf("%s\n", u);
			ls.push_back(u);
			idx[u] = i;
		}
		scanf("%d\n", &E);
		for(i = 0; i < E; i++){
			scanf("%s %s\n", u, w);
			adj[u].push_back(w);
			inc[w]++;
		}
		vs ts = kahn(ls, adj, inc, idx);
		printf("Case #%d: Dilbert should drink beverages in this order:", ++T);
		for(auto it = ts.begin(); it != ts.end(); ++it){
			printf(" %s", it->c_str());
		}
		printf(".\n\n");
	}
	return 0;
}
