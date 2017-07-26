/*
 * Leonardo Deliyannis Constantin
 * UVa 11906 - Knight in a War Grid
 */

#include<stdio.h>
#include<string.h>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX 112

typedef pair<int, int> ii;

int R, C, M, N;
bool vis[MAX][MAX];
bool wet[MAX][MAX];

bool isValid(int i, int j){
	return 0 <= i && i < R && 0 <= j && j < C && !wet[i][j];
}

ii tour(int si, int sj){
	ii ret;
	int i, j, k, i2, j2, cnt;
	vector<int> di, dj;
	if(M == 0 || N == 0){
		if(M == 0) swap(M, N);
		di = { -M,  0,  0,  M };
		dj = {  0, -M,  M,  0 };
	}
	else if(M == N){
		di = { -M, -M,  M,  M };
		dj = { -M,  M, -M,  M };
	}
	else{
		di = { -M, -M, -N, -N,  N,  N,  M,  M };
		dj = { -N,  N, -M,  M, -M,  M, -N,  N };
	} 
	int tam = di.size();
	ret.first = ret.second = 0;
	memset(vis, false, sizeof(vis));
	vis[si][sj] = true;
	stack<ii> q;
	q.push(ii(si, sj));
	while(!q.empty()){
		i = q.top().first;
		j = q.top().second;
		q.pop();
		cnt = 0;
		for(k = 0; k < tam; k++){
			i2 = i+di[k];
			j2 = j+dj[k];
			if(isValid(i2, j2)){
				if(!vis[i2][j2]){
					vis[i2][j2] = true;
					q.push(ii(i2, j2));
				}
				cnt++;
			}
		}
		(cnt&1) ? ret.second++ : ret.first++;
	}
	return ret;
}

int main(){
	int T, W, x, y, tc = 0;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d %d", &R, &C, &M, &N);
		scanf("%d", &W);
		memset(wet, false, sizeof(wet));
		while(W--){
			scanf("%d %d", &x, &y);
			wet[x][y] = true;
		}
		ii ans = tour(0,0);
		printf("Case %d: %d %d\n", ++tc, ans.first, ans.second);
	}
	return 0;
}
