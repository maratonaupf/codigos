#include<stdio.h>

int cuadrado(int a, int b, int c){
	return a*a + b*b == c*c ||
		   a*a + c*c == b*b ||
		   b*b + c*c == a*a;
}

int main(void){
	int a, b, c;
	while(scanf("%d %d %d", &a, &b, &c) != EOF){
		if(a+b <= c || a+c <= b || b+c <= a){
			printf("Invalido\n");		
		}
		else{
			printf("Valido-");
			if(a == b && b == c) printf("Equilatero\n");
			else if(a == b || b == c || c == a) printf("Isoceles\n");
			else printf("Escaleno\n");
			printf("Retangulo: %c\n", cuadrado(a, b, c) ? 'S' : 'N');
		}
	}
	return 0;
}
