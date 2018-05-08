/*
 * Leonardo Deliyannis Constantin
 * URI 2775 - Preparando a Produção
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 1123
#define fst first
#define snd second

typedef pair<int, int> ii;

int main(){
	int N, i, j, cost;
	ii v[MAX];
	while(scanf("%d", &N) != EOF){
		for(i = 0; i < N; i++){
			scanf("%d", &v[i].fst);
		}
		for(i = 0; i < N; i++){
			scanf("%d", &v[i].snd);
		}
		cost = 0;
		for(i = 0; i < N; i++){
			for(j = 1; j < N; j++){
				if(v[j-1].fst > v[j].fst){
					swap(v[j-1], v[j]);
					cost += v[j-1].snd + v[j].snd;
				}
			}
		}
		printf("%d\n", cost);
	}
	return 0;
}
