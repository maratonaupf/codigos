#include<stdio.h>
#include<string.h>
#include<algorithm> // max()
using namespace std;
#define MAX 112

int main(void){
	int N, M, i, j, val, maior;
	int lin[MAX], col[MAX];
	while(scanf("%d %d", &N, &M) != EOF){
		memset(lin, 0, sizeof(lin));
		memset(col, 0, sizeof(col));
		maior = 0;
		for(i = 0; i < N; i++){
			for(j = 0; j < M; j++){
				scanf("%d", &val);
				lin[i] += val;
				col[j] += val;
			}
			maior = max(maior, lin[i]);
		}
		for(j = 0; j < M; j++)
			maior = max(maior, col[j]);
		printf("%d\n", maior);
	}
	return 0;
}
