#include<stdio.h>
#include<string.h> // memset()
#define MAX 112 // 100
/* Coloque a constante MAX sempre como um pouquinho 
 * a mais do que o problema pede; assim, você evita 
 * problemas com falta de espaço na alocação estática. 
 * E não fica perdido contando zeros na hora da prova ;-)
 * */

int t[MAX]; // tempo consumido por cada tarefa
int v[MAX]; // felicidade gerada por cada tarefa
int m[MAX][MAX]; // matriz onde computamos e 
// armazenamos os resultados do nosso...

// Algoritmo da Mochila 0-1: versão Bottom-Up (iterativa)
// N é a quantidade de itens, W é a capacidade da mochila
int mochila(int N, int W){
	int tempo, soma, i, j;
	// memset: útil pra preencher um vetor
	// ou matriz com valores 0 ou -1
	memset(m, 0, sizeof(m));
	for(i = 1; i <= N; i++){
		for(j = 1; j <= W; j++){
			tempo = m[i-1][j];
			if(t[i] <= j){
				soma = m[i-1][j-t[i]] + v[i];
				if(tempo < soma) tempo = soma;
			}
			m[i][j] = tempo;
		}
	}
	return m[N][W];
}
 
int main(void){
	int caso = 0;
	int L, N, i; // L = tempo limite; N = número de atividades
	// leia a entrada dentro do while ignorando o valor de scanf(),
	// como fiz com uma vírgula; o while rodará enquanto L != 0
	while(scanf("%d %d", &L, &N), L != 0){
		// em aritmética de ponteiros, t+i é a mesma coisa que &t[i]
		for(i = 1; i <= N; i++) scanf("%d", t+i);
		for(i = 1; i <= N; i++) scanf("%d", v+i);
		// computamos e imprimimos a resposta dentro do printf() mesmo ^^
		printf("Caso %d gera felicidade %d\n", ++caso, mochila(N, L));
	}
	return 0;
}
