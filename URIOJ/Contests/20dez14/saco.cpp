#include<cstdio>
#include<cstring>
#include<algorithm>

//#define max(x, y) ((x)>(y) ? (x) : (y))
#define MAX 112

using namespace std;
int total, maxpeso;
bool visitados[MAX];

bool buscar(int vet[], int n, int k){
	for(int i = 0; i < n; i++)
		if(vet[i] == k && !visitados[i]){
			visitados[i] = true;
			return true;
		}
	return false;
}

int knapSack(int W, int peso[], int qt[], int n){
	int i, w;
	int K[MAX][51], P[MAX][51];
	maxpeso = 0;
	// Build table K[][] in bottom up manner
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++){
			if (i==0 || w==0)
				K[i][w] = P[i][w] = 0;
			else if (peso[i-1] <= w){
				K[i][w] = max(qt[i-1] + K[i-1][w-peso[i-1]],  K[i-1][w]);
				P[i][w] = max(peso[i-1] + P[i-1][w-peso[i-1]], P[i-1][w]);
				//printf("peso: %d, P-: %d, P: %d\n", peso[i-1], P[i-1][w-peso[i-1]], P[i][w]);
			}else{ 
				K[i][w] = K[i-1][w];
				P[i][w] = P[i-1][w];
			}
		}
	}
	
	int ultimo = -1;
	total = 0;
	ultimo = K[i][0];
	i = n;
	for(int j = 1; j < W + 1; j++){
		//printf("%d ", K[i][j]);
		if(K[i][j] != ultimo){
			if(buscar(qt, n + 1, K[i][j] - ultimo))
				total++;		
		}
	
		ultimo = K[i][j];
	}
	total++;
	maxpeso = P[n][W];
	return K[n][W];
}

int main(){
	int N, pac, i, W=50, qt[MAX], peso[MAX], resp;
	scanf("%d", &N);
	while(scanf("%d", &pac)!=EOF){
		//scanf("%d", &pac);
		N--;
		for(i=0; i<pac; i++)
			scanf("%d %d", qt+i, peso+i);
		
		memset(visitados, false, sizeof(visitados));
		resp = knapSack(W, peso, qt, pac);
		
		printf("%d brinquedos\n", resp);
		printf("Peso: %d kg\n", maxpeso);
		printf("sobra(m) %d pacote(s)\n\n", pac - total);
	}
	while(N--){
		printf("%d brinquedos\n", resp);
		printf("Peso: %d kg\n", maxpeso);
		printf("sobra(m) %d pacote(s)\n\n", pac - total);
	}
	return 0;
}
