/*
 * Leonardo Deliyannis Constantin
 * UVa 11228 - Transportation system.
 */

#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, ii> edge;
typedef vector<int> vi;
typedef vector<ii> vii;

class UnionFind{
private: vi p, rank;
public: 
	UnionFind(int N){
		p.assign(N, 0);
		rank.assign(N, 0);
		for(int i = 0; i < N; i++) p[i] = i; }
	int findSet(int i){
		return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j){ 
		return findSet(i) == findSet(j); }
	void unionSet(int i, int j){
		if(!isSameSet(i, j)){
			int x = findSet(i), y = findSet(j);
			if(rank[x] > rank[y]) p[y] = x;
			else {
				p[x] = y;
				if(rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};

struct point{
	int x, y;
	point(){ x = y = 0; }
	point(int _x, int _y): x(_x), y(_y) {}
};

double dist(point p1, point p2){
	return hypot(p1.x - p2.x, p1.y - p2.y); }

iii kruskal(int N, int R, vector<edge> &els){
	double roads, rails;
	int states = 0;
	roads = rails = 0.0;
	sort(els.begin(), els.end());
	UnionFind UF(N);
	for(auto it = els.begin(); it != els.end(); ++it){
		edge e = *it;
		if(!UF.isSameSet(e.second.first, e.second.second)){
			UF.unionSet(e.second.first, e.second.second);
			if(e.first <= R)
				roads += e.first;
			else{
				rails += e.first;
				states += (states == 0) ? 2 : 1;
			}
		}
	}
	if(states == 0) states = 1;
	return iii(states, ii(roads + 0.5, rails + 0.5));
}

int main(){
	int T, N, R, tc, x, y, i, j;
	int states, roads, rails;
	scanf("%d", &T);
	for(tc = 1; tc <= T; tc++){
		scanf("%d %d", &N, &R);
		vector<point> v;
		vector<edge> els;
		for(i = 0; i < N; i++){
			scanf("%d %d", &x, &y);
			v.push_back(point(x, y));
			for(j = 0; j < i; j++){
				double d = dist(v[i], v[j]);
				els.push_back(edge(d, ii(i, j)));
			}
		}
		iii ans = kruskal(N, R, els);
		states = ans.first;
		roads = ans.second.first;
		rails = ans.second.second;
		printf("Case #%d: %d %d %d\n", tc, states, roads, rails);
	}
	return 0;
}
