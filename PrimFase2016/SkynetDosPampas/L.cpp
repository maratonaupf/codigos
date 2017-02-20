#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
using namespace std;
//#define MSET(arr,val) memset(arr, val, sizeof(val))
#define MAX 212
#define INFTO 112345678
typedef pair<int, int> ii;
typedef map<int, int> mii;
//#define DEBP 1

int R, C;
int grid[MAX][MAX];
bool vis[MAX][MAX];

int di[] = { -1, 0, 1, 0 };
int dj[] = { 0, -1, 0, 1 };
int area[10];

int dfs(int si, int sj){
	int ret = 0;
	int i, j, k, i2, j2;
	vis[si][sj] = true;
	stack<ii> st;
	st.push(ii(si, sj));
	while(!st.empty()){
		i = st.top().first;
		j = st.top().second;
		st.pop();
		ret++; // should this line be here?
		for(k = 0; k < 4; k++){
			i2 = i+di[k]; j2 = j+dj[k];
			if(i2 >= 0 && i2 < R && j2 >= 0 && j2 < C && !vis[i2][j2]){
				if(grid[i2][j2] == grid[i][j]){
					vis[i+di[k]][j+dj[k]] = true;
					st.push(ii(i+di[k], j+dj[k]));
				}
			}
		}
	}
	#ifdef DEBP
	printf("RET = %d\n", ret);
	#endif
	return ret;
}

void pinta(vector<ii> &v, int color){
	int tam = (int) v.size();
	for(int i = 0; i < tam; i++){
		grid[v[i].first][v[i].second] = color;
	}
}

void printMat(){
	puts("===== DEBUG =====");
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			printf("%d%c", grid[i][j], j < C-1 ? ' ' : '\n');
		}
	}
}

int main(void){
	int i, j;
	while(scanf("%d %d", &R, &C) != EOF){
		mii m;
		set<int> s;
		vector<ii> zeros;
		for(i = 0; i < R; i++){
			for(j = 0; j < C; j++){
				scanf("%d", grid[i]+j);
				if(!grid[i][j]){
					zeros.push_back(ii(i,j));
				} 
				else if(!s.count(grid[i][j])){
					s.insert(grid[i][j]);
				}
			}
		}
		s.insert(0);
		int menorEver = -1;
		for(auto it = s.begin(); it != s.end(); ++it){
			memset(vis, 0, sizeof(vis));
			int menor = -1;
			pinta(zeros, *it);
			#ifdef DEBP
			printMat();
			#endif
			for(i = 0; i < R; i++){
				for(j = 0; j < C; j++){
					if(!vis[i][j]){
						menor = (menor == -1) ? dfs(i, j) :
							min(menor, dfs(i, j));
					}
				}
			}
			menorEver = (menorEver == -1) ? menor : min(menor, menorEver);
		}
		#ifdef DEBP
		printf("RESPOSTA == ");
		#endif
		printf("%d\n", menorEver);
		m.clear(); s.clear(); zeros.clear();
	}
	return 0;
}
