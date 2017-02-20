#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 1123

int kadane(int N, int v[], int cpd){
	int ret = 0, maxAtual = 0;
	for(int i = 0; i < N; i++){
		maxAtual = max(v[i]-cpd, maxAtual + v[i]-cpd);
		ret = max(ret, maxAtual);
	}
	return ret;
}

int main(void){
	int N, i, cpd, v[MAX];
	while(scanf("%d", &N) != EOF){
		scanf("%d", &cpd);
		for(i = 0; i < N; i++) scanf("%d", v+i);
		printf("%d\n", kadane(N, v, cpd));
	}
	return 0;
}
