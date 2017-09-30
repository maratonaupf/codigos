/*
 * Leonardo Deliyannis Constantin
 * URI 2665 - Hipercampo
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define INFTO ((int)1e9)

typedef vector<int> vi;
typedef pair<int, int> ii;

struct pt{
	int x, y;
	pt(){ x = y = 0; }
	pt(int _x, int _y): x(_x), y(_y) {}
};

struct vec{
	int x, y;
	vec(int _x, int _y): x(_x), y(_y) {}
};

struct triangle{
	pt a, b, c;
	triangle(){ a = b = c = pt(); }
	triangle(pt _a, pt _b, pt _c): a(_a), b(_b), c(_c) {}
};

vec toVec(const pt &a, const pt &b){
	return vec(b.x - a.x, b.y - a.y); }

double cross(const vec &a, const vec &b){
	return a.x * b.y - a.y * b.x; }

bool ccw(const pt &a, const pt &b, const pt &c){
	return cross(toVec(a, b), toVec(a, c)) > 0; }

bool insideTriangle(const pt &u, const triangle &t){
	return ccw(u, t.a, t.b) && ccw(u, t.b, t.c) && ccw(u, t.c, t.a); }

vector<vi> buildAdjList(int N, const pt &A, const pt &B, const vector<pt> &v, vi &arr){
	int u, w;
	vector<vi> LG(N, vi());
	arr.assign(N, 0);
	for(u = 0; u < N; u++){
		for(w = u+1; w < N; w++){
			if(insideTriangle(v[w], triangle(A, B, v[u]))){
				LG[u].push_back(w);
				arr[w]++; }}}
	return LG;
}

bool ycmp(const pt &a, const pt &b){ return a.y > b.y; }

vi toposort(const vector<vi> &LG, vi arr){
	vi ts;
	priority_queue<int, vector<int>, greater<int> > Q;
	for(int u = 0; u < (int)arr.size(); u++)
		if(arr[u] == 0)
			Q.push(u);
	while(!Q.empty()){
		int u = Q.top(); Q.pop(); ts.push_back(u);
		for(int i = 0; i < (int)LG[u].size(); i++){
			int w = LG[u][i];
			if(--arr[w] == 0){
				Q.push(w);
			}
		}
	}
	return ts;
}

int solve(int N, const pt &A, const pt &B, vector<pt> &v){
	sort(v.begin(), v.end(), ycmp);
	vector<int> arr;
	vector<vi> LG = buildAdjList(N, A, B, v, arr);
	vi ts = toposort(LG, arr);
	vi dist(N, -INFTO);
	for(int i = 0; i < N; i++)
		if(arr[ts[i]] == 0) 
			dist[ts[i]] = 1;
	for(int i = 0; i < N; i++){
		int u = ts[i];
		for(int j = 0; j < (int)LG[u].size(); j++){
			int w = LG[u][j];
			if(dist[w] < dist[u] + 1){
				dist[w] = dist[u] + 1;
			}
		}
	}
	return *max_element(dist.begin(), dist.end());
}

int main(){
	int N, xa, xb;
	while(scanf("%d %d %d", &N, &xa, &xb) != EOF){
		vector<pt> v(N, pt());
		for(int i = 0; i < N; i++){
			scanf("%d %d", &v[i].x, &v[i].y);
		}
		printf("%d\n", solve(N, pt(xa, 0), pt(xb, 0), v));
	}
	return 0;
}
