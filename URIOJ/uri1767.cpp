#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAX 112

using namespace std;
const int W = 50;

int mochila[MAX][MAX];
int val[MAX], peso[MAX];

int PD(int i, int w) {
	if(mochila[i][w] != -1) return mochila[i][w];
	if(i == 1 && peso[i] <= w) return mochila[i][w] = val[i];
	if(i == 1 || w == 0) return mochila[i][w] = 0; 
	if(peso[i] > w) return mochila[i][w] = PD(i - 1, w);
	return mochila[i][w] = max(PD(i - 1, w), PD(i - 1, w - peso[i]) + val[i]);
}

int main(void){
	int N, i, w, sobra, aux;
	int pac;
	scanf("%d", &N);
	while(N--){
		scanf("%d", &pac);
		for(i = 1; i <= pac; i++){
			scanf("%d %d", val+i, peso+i);
		}
		memset(mochila, -1, sizeof(mochila));
		w = W; 
		sobra = i = pac;
		aux = PD(pac, W);
		while(aux > 0){
			if(aux != mochila[i-1][w]){
				sobra--;
				w -= peso[i];
			}
			i--;
			aux = mochila[i][w];
		}
		printf("%d brinquedos\n", PD(pac, W));
		printf("Peso: %d kg\n", W-w);
		printf("sobra(m) %d pacote(s)\n\n", sobra);
	}
	return 0;
}
