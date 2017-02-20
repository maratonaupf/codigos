#include<stdio.h>
#include<utility> // pair<>
#include<vector> // vector<>
#include<algorithm> // min()
//#define DEBP // DEBug Prints:
// Descomente a macro acima caso 
// queira ver as CFCs dos grafos

using namespace std;

// Typedefs são atalhos e ajudam bastante
// na hora da prova, para você não precisar digitar tanto :-)
typedef pair<int, int> ii; // par de inteiros
typedef vector<int> vi; // vetor de inteiros
// vetor de vetor de inteiros: nossa implementação de grafo,
typedef vector<vi> grafo; // uma lista de adjacências
typedef vector<ii> vii; // vetor de pares de inteiros

int N, M; // N = qtd. de vértices, M = qtd. de arestas

// variáveis globais usadas pelo Algoritmo de Tarjan
vi ordem, ciclo, pilha; // pilha implementada em vetor mesmo, rsrs
vector<bool> empilhado;
int numSCC, contador; 

// recebe o vector<vector<int> > LG por referência,
// e um vértice u por valor, mesmo
void tarjanSCC(grafo &LG, int u){
	int j, v;
	ordem[u] = ciclo[u] = contador++;
	// empilhamos o vértice u
	pilha.push_back(u);
	empilhado[u] = true;
	// para cada vizinho de u
	for(j = 0; j < (int)LG[u].size(); j++){
		// seja v um vizinho de u
		v = LG[u][j];
		if(ordem[v] == 0){
			tarjanSCC(LG, v);
		}
		if(empilhado[v]){
			ciclo[u] = min(ciclo[u], ciclo[v]);
		}
	}
	
	if(ciclo[u] == ordem[u]){
		++numSCC;
		#ifdef DEBP
		printf("SCC %d:", numSCC);
		#endif
		while(true){
			v = pilha.back();
			pilha.pop_back();
			empilhado[v] = false;
			#ifdef DEBP
			printf(" %d", v);
			#endif
			if(u == v) break;
		}
		#ifdef DEBP
		printf("\n");
		#endif
	}
}

// recebe o vector<vector<int> > LG por referência
void tarjan(grafo &LG){
	ordem.assign(N+1, 0);
	ciclo.assign(N+1, 0);
	empilhado.assign(N+1, false);
	contador = numSCC = 0;
	for(int s = 1; s <= N; s++){
		if(ordem[s] == 0){
			tarjanSCC(LG, s);
		}
	}
}

int main(void){
	int u, w, dir, e;
	// Enquanto lermos N e M, 
	// e N for diferente de zero
	while(scanf("%d %d", &N, &M), N != 0){
		// criamos um vector<vector<int> > com N+1 posições,
		// pois os vértices vão de 1 a N, não de 0 a N-1
		grafo LG(N+1);
		// lemos as M arestas
		for(e = 1; e <= M; e++){
			// u é a origem; w é o destino
			// dir = 1 se a rua for de mão única, 
			// ou 2 se a rua for de mão dupla
			scanf("%d %d %d", &u, &w, &dir);
			// adicionamos w à vizinhança de u
			LG[u].push_back(w);
			// se a rua for de mão dupla, também
			// adicionamos u à vizinhança de w
			if(dir == 2) LG[w].push_back(u);
		}
		// rodamos o algoritmo de Tarjan
		// para descobrir a quantidade de
		// comp. fortemente conectadas
		tarjan(LG);
		// como o booleano em C/C++ é um inteiro, 
		// será impresso 1 se numSCC for igual a 1, 
		// ou 0, caso contrário
		printf("%d\n", numSCC == 1);
		// limpamos a lista de adjacência para o próximo caso
		LG.clear();
		pilha.clear();
	}
	return 0;
}
