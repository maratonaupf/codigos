#include<stdio.h>
#include<math.h> // hypot() = hipotenusa (obviamente)

int main(void){
	double D, VF, VG;
	double TG, TF;
	while(scanf("%lf %lf %lf", &D, &VF, &VG) != EOF){
		// podemos computar a distância entre o fugitivo 
		// e as águas internacionais usando hypot(D, 12.0), 
		// que é o mesmo que usar sqrt(D*D + 12.0*12.0)
		TG = hypot(D, 12.0) / VG; // tempo de fuga do ladrão
		TF = 12.0 / VF; // tempo da Guarda Costeira
		
		// "if" ternário: imprimimos uma string, 
		// "S" se TG for no máximo TF ou "N" caso contrário
		printf("%s\n", TG <= TF ? "S" : "N");
	}
	return 0;
}

