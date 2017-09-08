/*
 * Leonardo Deliyannis Constantin
 * UVa 11747 - Heavy Cycle Edges
 */

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> edge;
typedef vector<int> vi;

class UnionFind{
private: vi p, rank;
public:
	UnionFind(int N){
		rank.assign(N, 0); p.assign(N, 0);
		for(int i = 0; i < N; i++){ p[i] = i; }}
	int findSet(int i){
		return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j); }
	void unionSet(int i, int j){
		int x = findSet(i), y = findSet(j);
		if(rank[x] > rank[y]) p[y] = x;
		else{ 
			p[x] = y;
			if(rank[x] == rank[y]) rank[y]++;
		}
	}
};

int N, E;

vi kruskal(const vector<edge> &els){
	int u, v, w;
	vi ret;
	UnionFind UF(N);
	for(int i = 0; i < E; i++){
		w = els[i].first;
		u = els[i].second.first;
		v = els[i].second.second;
		if(!UF.isSameSet(u, v)){
			UF.unionSet(u, v); }
		else{
			ret.push_back(w);
		}
	}
	if(!ret.empty()) 
		sort(ret.begin(), ret.end());
	return ret;
}

int main(){
	int i, u, v, w;
	while(scanf("%d %d", &N, &E), N != 0){
		vector<edge> els;
		for(i = 0; i < E; i++){
			scanf("%d %d %d", &u, &v, &w);
			els.push_back(edge(w, ii(u, v)));
		}
		sort(els.begin(), els.end());
		vi ans = kruskal(els);
		if(ans.empty())
			printf("forest\n");
		else{
			for(i = 0; i < (int)ans.size(); i++){
				if(i > 0) printf(" ");
				printf("%d", ans[i]);
			} printf("\n");
		}
	}
	return 0;
}
