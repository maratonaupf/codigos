#include<stdio.h>
#include<cmath>
#include<vector>
#include<algorithm>
#define EPS 1e-9
//#define DEBP

using namespace std;

struct point{ double x, y; };
typedef vector<point> vp;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<double, ii> edge;
typedef vector<edge> grafo;

// Computa a distância entre dois pontos 2D.
double dist(point a, point b){ return hypot(a.x - b.x, a.y - b.y); }

class UnionFind{
	private: vi p, rank;
	public:
	UnionFind(int N){
		rank.assign(N, 0); p.assign(N, 0);
		for(int i = 0; i < N; i++){ p[i] = i; }
	}
	int findSet(int i){ return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j){ return findSet(i) == findSet(j); }
	void unionSet(int i, int j){
		if(!isSameSet(i, j)){
			int x = findSet(i), y = findSet(j);
			if(rank[x] > rank[y]) p[y] = x;
			else{ p[x] = y;
				if(rank[x] == rank[y]) rank[y]++; }
		}
	}
};

int N;
double Kruskal(grafo &els){
	double mstCost = 0;
	int E = (int)els.size();
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
	int testCases, i, j;
	scanf("%d\n", &testCases);
	while(testCases--){
		scanf("%d", &N);
		vp V(N);
		grafo els;
		for(i = 0; i < N; i++){
			scanf("%lf %lf", &V[i].x, &V[i].y);
			for(j = 0; j < i; j++){
				els.push_back(edge(dist(V[j], V[i]), ii(j, i)));
			}
		}
		V.clear();
		printf("%.2lf\n", Kruskal(els) / 100.0);
		els.clear();
	}
	return 0;
}
