/*
 * Leonardo Deliyannis Constantin
 * URI 1925 - Ordan e as Novinhas
 */

#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1123

typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;

const int di[] = {-1,  0, 0, 1};
const int dj[] = { 0, -1, 1, 0};

int L, C, ncomp;
char grid[MAX][MAX];
vector<vb> vis;
vector<vi> nov;
vector<vi> cc;
vi comps;

bool isValid(int i, int j){
	return 0 <= i && i < L && 0 <= j && j < C 
		&& grid[i][j] == 'n';
}

int dfs(int si, int sj){
	if(vis[si][sj]) return nov[si][sj];
	int i, j, k, i2, j2;
	vis[si][sj] = true;
	stack<ii> S;
	vector<ii> v;
	S.push(ii(si, sj));
	while(!S.empty()){
		v.push_back(S.top());
		i = S.top().first;
		j = S.top().second;
		S.pop();
		for(k = 0; k < 4; k++){
			i2 = i+di[k];
			j2 = j+dj[k];
			if(isValid(i2, j2) && !vis[i2][j2]){
				vis[i2][j2] = true;
				S.push(ii(i2, j2));
			}
		}
	}
	for(i = 0; i < (int)v.size(); i++){
		nov[v[i].first][v[i].second] = (int)v.size();
		cc[v[i].first][v[i].second] = ncomp;
	}
	ncomp++;
	return nov[si][sj];
}

bool sameComponent(int i, int j){
	for(int a = 0; a < (int)comps.size(); a++){
		if(cc[i][j] == comps[a]) return true;
	}
	return false;
}

void countNovinhasNearby(int i, int j){
	comps.clear();
	int k, i2, j2, ans = 0;
	for(k = 0; k < 4; k++){
		i2 = i+di[k];
		j2 = j+dj[k];
		if(isValid(i2, j2) && !sameComponent(i2, j2)){
			ans += dfs(i2, j2);
			comps.push_back(cc[i2][j2]);
		}
	}
	nov[i][j] = ans;
}

int main(){
	int i, j, ai, aj;
	while(scanf("%d %d\n", &L, &C) != EOF){
		for(i = 0; i < L; i++){
			fgets(grid[i], MAX, stdin);
			grid[i][C] = 0;
		}
		ncomp = 0;
		ai = aj = -1;
		vis.assign(L, vb(C, false));
		nov.assign(L, vi(C, 0));
		cc.assign(L, vi(C, -1));
		for(i = 0; i < L; i++){
			for(j = 0; j < C; j++){
				if(grid[i][j] == '*'){
					countNovinhasNearby(i, j);
					if(ai == -1 || nov[i][j] > nov[ai][aj]){
						ai = i; aj = j;
					}
				}
			}
		}
		printf("%d,%d\n", ai+1, aj+1);
	}
	return 0;
}
