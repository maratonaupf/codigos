/*
 * Leonardo Deliyannis Constantin
 * UVa 1234 - RACING
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
		return findSet(i) == findSet(j);
	}
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

int kruskal(const vector<edge> &els){
	int ret = 0;
	UnionFind UF(N);
	for(int i = 0; i < E; i++){
		edge e = els[i];
		if(!UF.isSameSet(e.second.first, e.second.second)){
			ret += e.first;
			UF.unionSet(e.second.first, e.second.second);
		}
	}
	return ret;
}

bool revCmp(const edge &a, const edge &b){ return a > b; }

int main(){
	int c, i, u, v, w, total;
	while(scanf("%d", &c), c != 0){
		while(c--){
			vector<edge> els;
			total = 0;
			scanf("%d %d", &N, &E);
			for(i = 0; i < E; i++){
				scanf("%d %d %d", &u, &v, &w);
				els.push_back(edge(w, ii(u-1, v-1)));
				total += w;
			}
			sort(els.begin(), els.end(), revCmp);
			printf("%d\n", total - kruskal(els));
		}
	}
	return 0;
}
