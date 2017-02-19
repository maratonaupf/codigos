#include<stdio.h>
#define MAX 21

void readmat(double m[][MAX], int N){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%lf", &m[i][j]);
		}
	}
}

double sum(double m[][MAX], int N, int &counter){
	int i, j;
	double acum = 0.0;
	counter = 0;
	for(i = 0; i < N; i++){
		for(j = i+1; j < (N-1)-i; j++){
			acum += m[i][j];
			counter++;
		}
	}
	return acum;
}

int main(void){
	const int N = 12;
	double m[MAX][MAX];
	char op;
	while(scanf(" %c", &op) != EOF){
		readmat(m, N);
		int counter;
		double ans = sum(m, N, counter);
		printf("%.1lf\n", op == 'S' ? ans : ans / (double)counter);
	}
	return 0;
}
