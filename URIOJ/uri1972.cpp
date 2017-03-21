#include<stdio.h>
#include<queue>
#include<utility>
#include<vector>
#include<bitset>
#include<map>
#define MAX 512
#define INFTO 112345678
using namespace std;
#define DEBP
#ifdef DEBP
#include<cassert>
#endif

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N, M;
char mat[MAX][MAX];
bitset<MAX> ok[MAX];

int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };

int dijkstra(int si, int sj){
	vvi dist(N);
	int i, j, i2, j2, k, peso;
	for(i = 0; i < N; i++){
		dist[i].assign(M, INFTO);
		ok[i].reset();
	} 
	dist[si][sj] = 0;
	priority_queue<iii, vector<iii>, greater<iii> > pq;
	pq.push(iii(0, ii(si, sj)));
	while(!pq.empty()){
		i = pq.top().second.first; 
		j = pq.top().second.second; pq.pop();
		if(ok[i][j]) continue;
		ok[i][j] = true;
		if(mat[i][j] == 'E') return dist[i][j];
		for(k = 0; k < 4; k++){
			i2 = i+di[k]; j2 = j+dj[k];
			if(0 <= i2 && i2 < N && 0 <= j2 && j2 < M && mat[i2][j2] != '#'){
				peso = '0' <= mat[i2][j2] && mat[i2][j2] <= '9' ? 
					mat[i2][j2] - '0' : 0;
				if(dist[i2][j2] > dist[i][j] + peso){
					dist[i2][j2] = dist[i][j] + peso;
					pq.push(iii(dist[i2][j2], ii(i2, j2)));
				}
			}
		}
	}
	return -1;
}

int main(void){
	int i, j, si, sj;
	while(scanf("%d %d\n", &N, &M) != EOF){
		si = sj = -1;
		for(i = 0; i < N; i++){
			fgets(mat[i], MAX, stdin);
			for(j = 0; mat[i][j] != '\n'; j++){
				if(mat[i][j] == 'H'){ si = i;  sj = j; }
			}
		}
		assert(si != -1 && sj != -1);
		int ret = dijkstra(si, sj);
		if(ret != -1) printf("%d\n", ret);
		else printf("ARTSKJID\n");
	}
	return 0;
}
