#include<stdio.h>
#define EPS 1e-9

int dblcmp(double a, double b){
	return (a + EPS < b) ? -1 : (a > b + EPS) ? 1 : 0;
}

double URM(double w, double r){
	return w * (1.0 + r / 30.0);
}

const char frase[5][32] = {
	"Nao vai da nao",
	"E 13",
	"Bora, hora do show! BIIR!",
	"Ta saindo da jaula o monstro!",
	"AQUI E BODYBUILDER!!"
};

int res(double M){
	if(dblcmp(M, 13.0) == -1) return 0;
	if(dblcmp(M, 14.0) == -1) return 1;
	if(dblcmp(M, 40.0) == -1) return 2;
	if(dblcmp(M, 60.0) !=  1) return 3;
	return 4;
}

int main(void){
	int W1, W2, R;
	double media, mgeral = 0.0;
	int casos = 0;
	while(scanf("%d %d %d", &W1, &W2, &R), W1){
		casos++;
		media = (URM(W1, R) + URM(W2, R)) / 2.0;
		printf("%s\n", frase[res(media)]);
		mgeral += media;
	}
	mgeral /= (double)casos;
	if(dblcmp(mgeral, 40.0) == 1){
		printf("\nAqui nois constroi fibra rapaz! Nao e agua com musculo!\n");
	}
	return 0;
}
