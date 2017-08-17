#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
#define MAX 112
#define INFTO 112345678
//#define DEBP 

typedef pair<int, int> ii;

int N, M;
int ci, cj; // origem das baratas
char grid[MAX][MAX];
int dist[MAX][MAX];
const int di[] = { -1,  0, 0, 1 };
const int dj[] = {  0, -1, 1, 0 };

void setaDist(){
	int i, j;
	for(i = 0; i < N; i++)
		for(j = 0; j< M; j++)
			dist[i][j] = INFTO;
}

void printGrid(){
	for(int i = 0; i < N; i++){
		puts(grid[i]);
	}
}

bool isValid(int i, int j){
	return 0 <= i && i < N && 0 <= j && j < M && grid[i][j] != '#';
}

void ff(int tempo){
	int i, j, k, i2, j2;
	tempo = (int)pow(4, tempo);
	queue<ii> Q;
	Q.push(ii(ci, cj));
	while(!Q.empty() && tempo--){
		i = Q.front().first;
		j = Q.front().second;
		Q.pop();
		for(k = 0; k < 4; k++){
			i2 = i+di[k];
			j2 = j+dj[k];
			if(isValid(i2, j2) && grid[i2][j2] != '*'){
				grid[i2][j2] = '*';
				Q.push(ii(i2, j2));
			}
		}
	}
}

int bfs(int si, int sj, int ti, int tj){
	int i, j, k, i2, j2;
	bool found = false;
	setaDist();
	dist[si][sj] = 0;
	queue<ii> Q;
	Q.push(ii(si, sj));
	while(!Q.empty() && !found){
		i = Q.front().first;
		j = Q.front().second;
		Q.pop();
		for(k = 0; k < 4; k++){
			i2 = i+di[k];
			j2 = j+dj[k];
			if(isValid(i2, j2) && grid[i][j] != '*'
			 && dist[i2][j2] == INFTO){
				dist[i2][j2] = dist[i][j] + 1;
				Q.push(ii(i2, j2));

			}
			if(i2 == ti && j2 == tj){ found = true; break; }
		}
	}
	return dist[ti][tj];
}

void setaPos(int i, int &v1, int &v2, const char *s){
	char *pos;
	if(v2 == -1 && (pos=strstr(grid[i], s)) != NULL){
		v2 = (int)(pos - grid[i]); 
		v1 = i;
	}
}

int main(){
	int i, T;
	int si, sj, ti, tj;
	scanf("%d\n", &T);
	while(T--){
		scanf("%d %d\n", &N, &M);
		si = ti = sj = tj = cj = -1;
		for(i = 0; i < N; i++){
			fgets(grid[i], MAX, stdin);
			grid[i][M] = 0;
			setaPos(i, si, sj, "S");
			setaPos(i, ti, tj, "X");
			setaPos(i, ci, cj, "*");
		}
		int tempo = bfs(si, sj, ti, tj);
		#ifdef DEBP
		printf("%d %d, %d %d, %d %d\n", si, sj, ti, tj, ci, cj);
		printGrid();
		puts("");
		#endif
		ff(tempo);
		#ifdef DEBP
		printf("TEMPO: %d\n", tempo);
		printGrid();
		#endif
		printf("%s\n", bfs(si, sj, ti, tj) != INFTO ? "yes" : "no");
	}
	return 0;
}
