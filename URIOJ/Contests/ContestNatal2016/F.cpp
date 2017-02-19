#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TAM 22
#define MAX 112

int cmps(const void *p1, const void *p2){
	return strcmp((char*)p1, (char*)p2);
}

int main(void){
	int N, i, good, bad;
	char v[MAX][TAM];
	char behavior;
	while(scanf("%d\n", &N) != EOF){
		good = bad = 0;
		for(i = 0; i < N; i++){
			scanf("%c %s\n", &behavior, v[i]);
			(behavior == '+') ? good++ : bad++;
		}
		qsort(v, N, sizeof(v[0]), &cmps);
		for(i = 0; i < N; i++){
			puts(v[i]);
		}
		printf("Se comportaram: %d | Nao se comportaram: %d\n", good, bad);
	}
	return 0;
}
