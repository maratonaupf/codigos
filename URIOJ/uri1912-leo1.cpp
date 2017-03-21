#include<stdio.h>
#include<algorithm>
#define MAX 112345
#define EPS 1e-5
//#define DEBP

using namespace std;

int cmp(double x, double y){
	return (x <= y + EPS) ? (x + EPS < y) ? -1 : 0 : 1;
}

double area(int N, int V[], double cut){
	double acum = 0.0;
	for(int i = 0; i < N; i++){
		if(cmp(V[i], cut) == 1)
			acum += max(0.0, (double)V[i] - cut);
	}
	return acum;
}

double binSearch(int N, int A, int V[], double hi){
	double lo = 0.0, mid = hi/2.0, ans = -1.0;
#ifdef DEBP
	unsigned its = 0;
#endif
	while(cmp(ans, (double)A)){
		ans = area(N, V, mid);
#ifdef DEBP
		++its;
		//printf("mid: %.5lf, ans: %.5lf, A: %d\n", mid, ans, A);
#endif
		if(ans > A) lo = mid;
		if(ans < A) hi = mid;
		mid = lo + (hi-lo) / 2.0;
	}
#ifdef DEBP
	printf("Tolerance: %.9lf\n", EPS);
	printf("%u iteration(s)\n", its);
#endif	
	return mid;
}

int main(void){
	int N, A;
	int V[MAX];
	while(scanf("%d %d", &N, &A), N){
		int acum = 0, hi = 0;
		for(int i = 0; i < N; i++){
			scanf("%d", V+i);
			acum += V[i];
			if(V[i] > hi) hi = V[i];
		}
		if(acum == A) printf(":D\n");
		else if(acum < A) printf("-.-\n");
		else printf("%.4lf\n", binSearch(N, A, V, hi));
	}
	return 0;
}
