#include<stdio.h>
#include<stack> // stack<> da STL (dá pra implementar uma na mão, mas ok)
#define MAX 31

using namespace std;

void isPossible(int N, char A[], char B[]){
	int i, j = 0;
	stack<char> s; // a estação é como uma pilha 
	
	// para cada vagão desejado em B
	for(i = 0; i < N; i++){
		if(s.empty()){
			// se a estação estiver vazia
			// "empilhamos" o vagão atual, e vamos ao próximo
			s.push(A[j++]);
			printf("I"); // relatamos a operação de inserção
		}
		// enquanto o vagão no topo da pilha não for o desejado
		while(s.top() != B[i]){
			if(j == N){
				// significa que não há mais vagões em A, logo,
				// a ordem esperada em B não pode ser satisfeita
				printf(" Impossible");
				return; // pulamos fora da função
			}
			// se ainda houver vagões em A, 
			// "empilhamos" um deles na estação, e vamos ao próximo
			s.push(A[j++]);
			printf("I"); // relatamos a inserção
		}
		// agora que temos o vagão desejado no topo da pilha, 
		// desempilhamos o mesmo, e relatamos a remoção
		s.pop();
		printf("R");
	}
}

int main(void){
	int N, i;
	char A[MAX]; // sequência dos vagões do lado A
	char B[MAX]; // sequência esperada para o lado B
	while(scanf("%d", &N), N){
		// lemos ambas as sequências, uma por vez // lembrando:
		for(i = 0; i < N; i++) scanf(" %c", A+i); // A+i == &A[i]
		for(i = 0; i < N; i++) scanf(" %c", B+i); // B+i == &B[i]
		// adicionamos o caractere nulo de 
		// terminação ao final de cada string
		A[N] = B[N] = '\0';
		// simula e vai imprimindo as operações
		isPossible(N, A, B);
		printf("\n");
	}
	return 0;
}
