#include<cstdio>

bool is_triangle(double A, double B, double C){
	return ((A < B+C) && (B < C+A) && (C < A+B));
}

bool tri_rectangle(double A, double B, double C){
	A*=A; B*=B; C*=C;
	return (A == B+C || B == A+C || C == A+B);
}

bool obtusangulo(double A, double B, double C){
	//~ A*=A; B*=B; C*=C;
	return ((A*A > B*B + C*C) || 
			(A*A + B*B < C*C) ||
			(A*A + C*C < B*B) );
}

bool isosceles(double A, double B, double C){
	return (A==B && B!=C) || (A==C && B!=C) || (B==C && B!=A);
}

int main(void){	
	double A, B, C;
	while(scanf("%lf %lf %lf", &A, &B, &C) != EOF){
		if(is_triangle(A,B,C)){
			puts((tri_rectangle(A,B,C)) ? "TRIANGULO RETANGULO" :
				(obtusangulo(A,B,C)) ?
				"TRIANGULO OBTUSANGULO" :
				"TRIANGULO ACUTANGULO" );
			if(A == B && B == C)
				puts("TRIANGULO EQUILATERO");
			else if(isosceles(A,B,C))
				puts("TRIANGULO ISOSCELES");
		}
		else puts("NAO FORMA TRIANGULO");
	}
	return 0;
}

