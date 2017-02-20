#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<utility>
#define MAX 112345
using namespace std;

struct proc{ int t, c; };

typedef long long ll;

// função de comparação de processos
int paircomp(const void *a, const void *b){ 
	return ((proc*)a)->t - ((proc*)b)->t;
}

int main(void){
	int N;
	proc v[MAX];
	while(scanf("%d", &N) != EOF){
		// fila de processos, cujo container é um vector
		// implementada como um MAX-heap
		priority_queue<pair<int, int>> fila;
		for(int i = 0; i < N; i++){
			// processos são inseridos na ordem contrária da entrada
			// ou seja, first é o tempo em que ele requisita execução
			// e second é a quantidade de ciclos que ele leva para ser executado
			scanf("%d %d", &v[i].t, &v[i].c);
		}
		// ordenamos os processos por tempo de requisição de execução
		qsort(v, N, sizeof(v[0]), &paircomp);
		
		// tempo inicia em 1
		int tempo = 1, i = 0;
		ll resp = 0LL;
		while(true){
			// enquanto houver processos a serem inseridos na fila
			// e o tempo de requisição for no máximo o tempo atual
			while(i < N && v[i].t <= tempo){
				// inserimos os processos na fila;
				fila.push(make_pair(-v[i].c, -v[i].t));
				i++;
			}
			// se a fila estiver vazia
			if(fila.empty()){
				// se não houverem mais processos, fim do laço
				if(i >= N) break;
				// tempo recebe o tempo de execução do
				// último processo inserido; continua o laço
				tempo = v[i].t;
				continue;
			}
			// retira um processo do topo da fila
			int pt = -fila.top().second; 
			int pc = -fila.top().first; 
			fila.pop();
			// incrementa a resposta (long long) 
			// com a diferença entre o tempo atual e 
			// o tempo em que o processo requisitou sua execução
			resp += (ll) (tempo - pt);
			// incrementamos o tempo com a quantidade de ciclos
			tempo += pc;
		}
		printf("%lld\n", resp);
	}
	return 0;
}
