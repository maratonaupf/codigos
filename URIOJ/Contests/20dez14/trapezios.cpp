#include<cstdio>

int main(){
	int T, nc;
	double Q, A, B, area;
	while(scanf("%d", &T), T){
		nc=0;
		while(nc++ < T){
			scanf("%lf %lf %lf", &Q, &A, &B);
			area=((A+B)*2.50) * Q;
			printf("Size #%d:\nIce Cream Used: %.2lf cm2\n", nc, area);
		}
		printf("\n");
	}
	return 0;
}
