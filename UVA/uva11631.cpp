/*
 * Leonardo Deliyannis Constantin
 * UVa 11631 - Dark Roads
 */

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> edge;
typedef vector<int> vi;

class UnionFind {
private: vi id, sz;
public:
	UnionFind(int N){ 
		sz.assign(N, 0);
		id.assign(N, 0);
		for(int i = 0; i < N; i++){
			id[i] = i;
		}
	}
	int findSet(int i){
		return (id[i] == i) ? i : (id[i] = findSet(id[i]));
	}
	bool isSameSet(int i, int j){ 
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j){
		if(!isSameSet(i, j)){
			int x = findSet(i), y = findSet(j);
			if(sz[x] > sz[y])
				id[y] = x;
			else {
				id[x] = y;
				if(sz[x] == sz[y]) sz[y]++;
			}
		}
	}
};

int kruskal(const int V, const int E, const vector<edge> &els){
	int mst_cost = 0;
	UnionFind UF(V);
	for(int i = 0; i < E; i++){
		edge front = els[i];
		if(!UF.isSameSet(front.second.first, front.second.second)){
			mst_cost += front.first;
			UF.unionSet(front.second.first, front.second.second);
		}
	}
	return mst_cost;
}

int main(){
	int V, E;
	int x, y, z;
	int allRoads;
	while(scanf("%d %d", &V, &E), V != 0){
		vector<edge> els;
		allRoads = 0;
		for(int i = 0; i < E; i++){
			scanf("%d %d %d", &x, &y, &z);
			els.push_back(edge(z, ii(x, y)));
			allRoads += z;
		}
		sort(els.begin(), els.end());
		printf("%d\n", allRoads - kruskal(V, E, els));
	}
	return 0;
}
