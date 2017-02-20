#include<stdio.h>
#define MAX 112345

int main(void){
	int N, K, i, topo;
	int c, s;
	int p[MAX];
	int isPossible;
	while(scanf("%d %d", &N, &K), N){
		topo = -1;
		isPossible = 1;
		for(i = 0; i < N; i++){
			scanf("%d %d", &c, &s);
			while(topo >= 0 && p[topo] <= c) topo--;
			if(topo == -1 || (s <= p[topo] && topo+1 < K)){
				p[++topo] = s;
			}else{
				isPossible = 0;
			}
		}
		printf("%s\n", isPossible ? "Sim" : "Nao");
	}
	
	return 0;
}
