#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 112

typedef struct _camiseta{
	char cor[16];
	char tam;
	char aluno[64];
} camiseta;

int cmp(const void *a, const void *b){
	camiseta ca = *(camiseta*)a;
	camiseta cb = *(camiseta*)b;
	int compcor = strcmp(ca.cor, cb.cor);
	if(compcor != 0) return compcor;
	int comptam = cb.tam - ca.tam;
	return (comptam != 0) ? comptam : strcmp(ca.aluno, cb.aluno);
}

int main(void){
	int N, i;
	int first = 1;
	camiseta v[MAX];
	while(scanf("%d\n", &N), N){
		if(first) first = 0;
		else printf("\n");
		
		for(i = 0; i < N; i++){
			fgets(v[i].aluno, 64, stdin);
			scanf("%s %c\n", v[i].cor, &v[i].tam);
		}
		qsort(v, N, sizeof(v[0]), cmp);
		for(i = 0; i < N; i++){
			printf("%s %c %s", v[i].cor, v[i].tam, v[i].aluno);
		}
	}
	return 0;
}
