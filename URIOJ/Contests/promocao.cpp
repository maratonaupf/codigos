#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAX 110
using namespace std;
 
int max(int a, int b) { return (a > b)? a : b; }

// Algoritmo da Mochila 0-1
int knapSack(int W, int wt[], int val[], int n){
	int i, w;
	int K[n+1][W+1];
	for(i=0; i<=n; i++) {
		for(w=0; w<=W; w++){
			if (i==0 || w==0) K[i][w] = 0;
			else if (wt[i-1] <= w)
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
			else K[i][w] = K[i-1][w];
		}
	}
	return K[n][W];
}

int main(){
	int n, i, W, wt[MAX], val[MAX];
	while(scanf("%d", &n), n){
		for(i=0; i<n; i++)
			scanf("%d %d", &val[i], &wt[i]);
		scanf("%d", &W);
		printf("%d\n", knapSack(W, wt, val, n));
	}
	return EXIT_SUCCESS;
}
