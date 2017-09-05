#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
#define MAX 112
#define INFTO ((int)1e9)

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int N, M, L;
const int di[] = { 
	-1,  0,  0,  1, -2,  0,  0,  2, 
	-2,  2, -1,  1, -1,  1, -2,  2, 
	-2,  0,  0,  2, -1,  0,  0,  1
};
const int dj[] = { 
	 0, -1,  1,  0,  0, -2,  2,  0, 
	-1,  1, -2,  2,  2, -2,  1, -1, 
	 0, -2,  2,  0,  0, -1,  1,  0
};
const int dk[] = { 
	-2, -2, -2, -2, -1, -1, -1, -1, 
	 0,  0,  0,  0,  0,  0,  0,  0, 
	 1,  1,  1,  1,  2,  2,  2,  2
};

vector<vvi> dist;
vector<vvb> viz;

bool isValid(int i, int j, int k){
	return 0 <= i && i < N 
		&& 0 <= j && j < M 
		&& 0 <= k && k < L;
}

int bfs(int si, int sj, int sk, int ti, int tj, int tk){
	int v, i, j, k, i2, j2, k2;
	dist.assign(N, vvi(M, vi(L, INFTO)));
	viz.assign(N, vvb(M, vb(L, false)));
	dist[si][sj][sk] = 0;
	queue<iii> Q;
	Q.push(iii(si, ii(sj, sk)));
	while(!Q.empty()){
		i = Q.front().first;
		j = Q.front().second.first;
		k = Q.front().second.second;
		Q.pop();
		for(v = 0; v < 24; v++){
			i2 = i+di[v];
			j2 = j+dj[v];
			k2 = k+dk[v];
			if(isValid(i2, j2, k2) && 
				dist[i2][j2][k2] == INFTO){
				dist[i2][j2][k2] = dist[i][j][k] + 1;
				Q.push(iii(i2, ii(j2, k2)));
			}
		}
	}
	return dist[ti][tj][tk];
}

inline int bfs(const iii &s, const iii &t){
	return bfs(s.first, s.second.first, s.second.second, 
		t.first, t.second.first, t.second.second); 
}

inline void decrement(iii &a){
	a.first--;
	a.second.first--;
	a.second.second--;
}

inline void readTrio(iii &a){
	scanf(" %d %d %d", &a.first, 
		&a.second.first, &a.second.second);
	decrement(a);
}

int main(){
	iii a, b;
	while(scanf(" %d %d %d", &N, &M, &L) != EOF){
		readTrio(a);
		readTrio(b);
		printf("%d\n", bfs(a, b));
	}
	return 0;
}
