#include<stdio.h>
#define MAX 112345

int bit[MAX];
void update(int i, int val){
	while(i <= MAX){
		bit[i] += val;
		i += i&-i;
	}
}

int readVal(int i){
	int ret = 0;
	while(i > 0){
		ret += bit[i];
		i -= i&-i;
	}
}

int main(void){
	int N, i, j;
	int v[MAX];
	int pares;
	while(scanf("%d", &N) != EOF){
		for(i = 0; i < N; i++){
			scanf("%d", v+i);
		}
		pares = 0;
		for(i = 1; i < N; i++){
			for(j = 0; j < i; j++){
				if(v[j] > v[i])
					pares++;
			}
		}
		printf("%d\n", pares);
	}
	return 0;
}
