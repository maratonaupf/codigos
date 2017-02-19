#include<stdio.h>
#define MAX 11234

bool isPeak(int a, int b, int c){
	return (a < b && b > c) || (a > b && b < c);
}

int main(void){
	int N, i;
	int v[MAX];
	int peaks;
	while(scanf("%d", &N), N){
		peaks = 0;
		for(i = 0; i < N; i++){
			scanf("%d", v+i);
		}
		if(isPeak(v[N-2], v[N-1], v[0])){ 
			peaks++;
		}
		if(isPeak(v[N-1], v[0], v[1])){
			peaks++;
		}
		for(i = 2; i < N; i++){
			if(isPeak(v[i-2], v[i-1], v[i])){
				peaks++;
			}
		}
		printf("%d\n", peaks);
	}
	return 0;
}
