#include<stdio.h>
#include<string.h>
#define MAX 112345
//#define DEBP

char nome[MAX][16];
int N;
long long PA, PB, power[MAX], A4, B4;

void simulation(int idx){
	int i;
	
	PA = PB = 0;
	
	for(i = 0; i <= idx; i++){
		PA += power[i] * (1 + idx - i);
	}
	for(i = idx + 1; i < N; i++){
		PB += power[i] * (i - idx);
	}
#ifdef DEBP
	puts("TERMINOU SIMULATION");
#endif
}

int buscabin(){
	int lo = 0, hi = N - 1, mid;
	A4 = B4 = 0;
	while(lo != hi){
		mid = lo + (hi-lo) / 2; // avoid overflows
		simulation(mid);
		if(PA < PB) lo = mid;
		if(PA > PB) hi = mid;
		if(PA == PB || (PA == A4 && PB == B4)) break;
		A4 = PA; B4 = PB;
	}
	return (PA == PB) ? mid : -1;
}

int main(void){
	int i, j, resp;
	while(scanf("%d", &N), N){
		getchar();
		memset(power, 0, sizeof(power));	
		for(i = 0; i < N; i++){
			scanf("%s", nome[i]);
			for(j=0; nome[i][j]; j++){
				power[i] += nome[i][j];
			}
		}
		resp = buscabin();
		puts(resp != -1 ? nome[resp] : "Impossibilidade de empate.");
	}
	return 0;
}
