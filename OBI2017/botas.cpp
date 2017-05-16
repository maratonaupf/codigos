#include<stdio.h>
#include<string.h>
#define MAX 31

int main(){
	int N, M, i;
	int pares;
	char C;
	int esq[MAX], dir[MAX];
	while(scanf("%d\n", &N) != EOF){
		memset(esq, 0, sizeof(esq));
		memset(dir, 0, sizeof(dir));
		while(N--){
			scanf("%d %c\n", &M, &C);
			C == 'E' ? esq[M-30]++ : dir[M-30]++;
		}
		pares = 0;
		for(i = 0; i < MAX; i++){
			if(esq[i] != 0 && esq[i] == dir[i])
				pares++;
		}
		printf("%d\n", pares);
	}
	return 0;
}
