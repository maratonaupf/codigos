#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<utility>
#define MAX 112345
using namespace std;

struct proc{ int t, c; };

typedef long long ll;

int paircomp(const void *a, const void *b){ 
	return ((proc*)a)->t - ((proc*)b)->t;
}

int main(void){
	int N;
	proc v[MAX];
	while(scanf("%d", &N) != EOF){
		priority_queue<pair<int, int>> fila;
		for(int i = 0; i < N; i++){
			scanf("%d %d", &v[i].t, &v[i].c);
		}
		qsort(v, N, sizeof(v[0]), &paircomp);
		
		int tempo = 1, i = 0;
		ll resp = 0LL;
		while(true){
			while(i < N && v[i].t <= tempo){
				fila.push(make_pair(-v[i].c, -v[i].t));
				i++;
			}
			if(fila.empty()){
				if(i >= N) break;
				tempo = v[i].t;
				continue;
			}
			int pt = -fila.top().second; 
			int pc = -fila.top().first; 
			fila.pop();
			resp += (ll) (tempo - pt);
			tempo += pc;
		}
		printf("%lld\n", resp);
	}
	return 0;
}
