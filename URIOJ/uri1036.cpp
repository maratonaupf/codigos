#include<cstdio>
#include<cmath>
int main(void){	
	double A, B, C, x1, x2, delta;
	while(scanf("%lf %lf %lf", &A, &B, &C) != EOF){
		delta = (B * B) - (4.0 * A * C);
		if (delta < 0.0 || A == 0.0)
			puts("Impossivel calcular");
		else{
			x1 = (-B + sqrt(delta)) / (2.0 * A);
			x2 = (-B - sqrt(delta)) / (2.0 * A);
			printf("R1 = %.5lf\nR2 = %.5lf\n", x1, x2);
		}
	}
	return 0;
}
