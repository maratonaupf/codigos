/*
 * Leonardo Deliyannis Constantin
 * UVa 929 - Number Maze
 */

#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
#define INFTO ((int)1e9)

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;

int N, M;
vector<vi> w;

const int di[] = {-1,  0, 0, 1 };
const int dj[] = { 0, -1, 1, 0 };

inline bool isValid(int i, int j){
	return 0 <= i && i < N && 0 <= j && j < M;
}

int dijkstra(int si, int sj, int ti, int tj){
	int i, j, k, i2, j2;
	vector<vi> dist(N, vi(M, INFTO));
	dist[si][sj] = w[si][sj];
	priority_queue<iii, vector<iii>, greater<iii> > Q;
	Q.push(iii(0, ii(si, sj)));
	while(!Q.empty()){
		i = Q.top().second.first;
		j = Q.top().second.second;
		Q.pop();
		for(k = 0; k < 4; k++){
			i2 = i+di[k];
			j2 = j+dj[k];
			if(isValid(i2, j2) &&
				dist[i2][j2] > dist[i][j] + w[i2][j2]){
				dist[i2][j2] = dist[i][j] + w[i2][j2];
				Q.push(iii(dist[i2][j2], ii(i2, j2)));
			}
		}
	}
	return dist[ti][tj];
}

int main(){
	int T, i, j;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &N, &M);
		w.assign(N, vi(M, 0));
		for(i = 0; i < N; i++){
			for(j = 0; j < M; j++){
				scanf("%d", &w[i][j]);
			}
		}
		printf("%d\n", dijkstra(0, 0, N-1, M-1));
	}
	return 0;
}
