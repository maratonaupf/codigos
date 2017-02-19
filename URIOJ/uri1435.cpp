#include<stdio.h>
//#define MAX 100
//const int MAX = 100;
int menor(int a, int b){
	if(a < b) return a;
	return b;
}

int main(void){
	int N;
	int dist;
	//int mat[MAX][MAX];
	//while(cin >> N, N != 0){
	while(scanf("%d", &N), N){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				dist = menor(menor(i+1, N-i), menor(j+1, N-j));
				if(j > 0) printf(" ");
				printf("%3d", dist);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
