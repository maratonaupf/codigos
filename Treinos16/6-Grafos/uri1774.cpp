#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
//#define DEBP

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> edge;
typedef vector<int> vi;

int N, E;
vector<edge> els;

class UnionFind{
	private: vi p, rank;
	public:
	UnionFind(int N){
		rank.assign(N, 0);
		p.assign(N, 0);
		for(int i = 0; i < N; i++){
			p[i] = i;
		}
	}
	int findSet(int i){
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j){
		if(!isSameSet(i, j)){
			int x = findSet(i), y = findSet(j);
			if(rank[x] > rank[y]) p[y] = x;
			else{ p[x] = y;
				if(rank[x] == rank[y]) rank[y]++; }
		}
	}
};

int Kruskal(){
	int mstCost = 0;
	sort(els.begin(), els.end());
	UnionFind UF(N);
	for(int i = 0; i < E; i++){
		edge front = els[i];
		if(!UF.isSameSet(front.second.first, front.second.second)){
			mstCost += front.first;
			UF.unionSet(front.second.first, front.second.second);
		}
	}
	return mstCost;
}

int main(void){
	int u, w, peso;
	while(scanf("%d %d", &N, &E) != EOF){
		els.reserve(E);
		for(int i = 0; i < E; i++){
			scanf("%d %d %d", &u, &w, &peso);
			els.push_back(edge(peso, ii(u-1,w-1)));
		}
		printf("%d\n", Kruskal());
		els.clear();
	}
	return 0;
}
