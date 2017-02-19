#include<cstdio>
#include<cmath>
#define PI 3.141592654

int main(){
	double A, B, C,
		pH, H, quant ;
	while(scanf("%lf %lf %lf", &A, &B, &C)!=EOF){
		pH = tan(A * PI / 180.0) * B;
		H = pH + C;
		quant = H * 5.0;
		printf("%.2lf\n", quant);
	}
	return 0;
}
