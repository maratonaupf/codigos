/*
 * Leonardo Deliyannis Constantin
 * UVa 821 - Page Hopping
 */

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 112
#define INFTO ((int)1e9)

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void floyd_warshall(int N, vector<vi> &AG){
	int i, j, k;
	for(k = 0; k < N; k++)
		for(i = 0; i < N; i++)
			for(j = 0; j < N; j++)
				AG[i][j] = min(AG[i][j], AG[i][k] + AG[k][j]);
}

int main(){
	int N;
	int c = 0, u, v, hi, i, j;
	int sum, cont;
	double avg;
	while(scanf("%d %d", &u, &v), u != 0){
		vii els;
		hi = max(u, v);
		els.push_back(ii(u, v));
		while(scanf("%d %d", &u, &v), u != 0){
			hi = max(hi, max(u, v));
			els.push_back(ii(u, v));
		}
		
		N = hi+1;
		vector<vi> AG(N, vi(N, INFTO));
		for(i = 0; i < (int)els.size(); i++){
			AG[els[i].first][els[i].second] = 1; 
		}
		floyd_warshall(N, AG);
		
		sum = cont = 0;
		for(i = 1; i < N; i++){
			for(j = 1; j < N; j++){
				if(i == j) continue;
				if(AG[i][j] < INFTO){
					sum += AG[i][j];
					cont++;
				}
			}
		}
		avg = (double)sum / (double)cont;
		printf("Case %d: average length between pages = ", ++c);
		printf("%.3lf clicks\n", avg);
	}
	return 0;
}
