#include<stdio.h>
#include<string.h> // memset()
#include<algorithm> // max(a, b)
#define MAX 112 // 100
/* Coloque a constante MAX sempre como um pouquinho 
 * a mais do que o problema pede; assim, você evita 
 * problemas com falta de espaço na alocação estática. 
 * E não fica perdido contando zeros na hora da prova ;-)
 * */
using namespace std; // por causa da biblioteca <algorithm> do C++

int t[MAX]; // tempo consumido por cada tarefa
int v[MAX]; // felicidade gerada por cada tarefa
int m[MAX][MAX]; // matriz onde computamos e 
// armazenamos os resultados do nosso...

// Algoritmo da Mochila 0-1: versão Top-Down (recursiva)
// i é a tarefa; h é o tempo (ou "peso")
int mochila(int i, int j) {
	// se já tivermos computado este estado, retornamos ele mesmo
	if(m[i][j] != -1) return m[i][j];
	if (i == 1 && t[i] <= j) return m[i][j] = v[i];
	if (i == 1) return m[i][j] = 0;
	if (j == 0) return m[i][j] = 0;
	if (t[i] > j) return m[i][j] = mochila(i - 1, j);
	return m[i][j] = max(mochila(i - 1, j), mochila(i - 1, j - t[i]) + v[i]);
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
		// memset: útil pra preencher um vetor
		// ou matriz com valores 0 ou -1
		memset(m, -1, sizeof(m));
		// computamos e imprimimos a resposta dentro do printf() mesmo ^^
		printf("Caso %d gera felicidade %d\n", ++caso, mochila(N, L));
	}
	return 0;
}
