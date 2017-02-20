#include<stdio.h>
#include<string.h>
#define MAX 1123456789
int v[MAX];

int main(){
	int N, M, i, menor, aux;
	while(scanf("%d %d", &N, &M) != EOF){
		memset(v, 0, M * sizeof(int));
		while(N--){
			for(i = 0; i < M; i++){
				scanf("%d", &aux);
				v[i] += aux;
			}
		}
		menor = v[0];
		for(i = 1; i < M; i++){
			if(v[i] < menor) menor = v[i];
		}
		printf("%d\n", menor);
	}
	return 0;
}
