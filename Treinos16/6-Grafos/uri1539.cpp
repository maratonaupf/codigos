#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm> // min()
using namespace std;
#define MSET(a,v) memset(a, v, sizeof(a))
#define MAX 112
#define INFTO 1000000000
// fine INFTO 1123456789

int N;
double AG[MAX][MAX];
int x[MAX], y[MAX], r[MAX];

int hypotSquared(int a, int b){
	return a*a + b*b;
}

void buildGraph(){
	int i, j;
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			AG[i][j] = (i == j) ? 0 : INFTO;
			
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			int d = hypotSquared(x[i] - x[j], y[i] - y[j]);
			if(d < r[i]*r[i]){
				AG[i][j] = sqrt(d);
			}
		}
	}
}

void floydWarshall(){
	for(int k = 0; k < N; k++)
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				AG[i][j] = min(AG[i][j], AG[i][k] + AG[k][j]);
}

int main(void){
	int C, i, j;
	while(scanf("%d", &N) != EOF && N != 0){
		//MSET(x, 0); MSET(y, 0); MSET(r, 0);
		for(i = 0; i < N; i++){
			scanf("%d %d %d", x+i, y+i, r+i);
		}
		buildGraph();
		floydWarshall();
		scanf("%d", &C);
		while(C--){
			scanf("%d %d", &i, &j); i--; j--;
			printf("%d\n", AG[i][j] != INFTO ? (int)AG[i][j] : -1);
		}
	}
	return 0;
}
