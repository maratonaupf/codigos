#include<cstdio>
#include<cstring>
#define MAX 22

typedef unsigned long long ull;

int main(){
	int N, M, i, j, mn=3, sp[MAX];
	ull m[MAX][MAX], maior[MAX], aux;
	char s[32];
	scanf("%d", &N);
	while(N--){
		scanf("%d", &M);
		memset(maior, 0, sizeof(maior));
		memset(sp, 0, sizeof(sp));
		for(i=0; i<M; i++){
			for(j=0; j<M; j++){
				scanf("%lld", &aux);
				m[i][j] = aux*aux;
			}
		}
		for(i=0; i<M; i++){
			for(j=0; j<M; j++)
				if(maior[i] < m[j][i])
					maior[i] = m[j][i];
			sprintf(s, "%llu", maior[i]);
			sp[i] = strlen(s);
		}
		printf("Quadrado da matriz #%d:\n", ++mn);
		for(i=0; i<M; i++){
			for(j=0; j<M; j++){ if(j) printf(" ");
				printf("%*llu", sp[j], m[i][j]);
			} printf("\n");
		}
		if(N) printf("\n");
	}
	return 0;
}
