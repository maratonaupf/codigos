#include<stdio.h>
#define MAX 112345

typedef long long ll;

int main(void){
	int N, v[MAX], i;
	while(scanf("%d", &N), N){
		for(i = 0; i < N; i++){
			scanf("%d", v+i);
		}
		
		ll resp = 0;
		for(i = 1; i < N; i++){
			resp += (v[i-1] >= 0) ? v[i-1] : -1 * v[i-1];
			v[i] += v[i-1];
		}
		
		printf("%lld\n", resp);
	}
	return 0;
}
