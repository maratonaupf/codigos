#include<cstdio>

double peso[4] = {2.0, 3.0, 4.0, 1.0};

int main(void){
	int i;	
	double N[4], med, ex;
	while(scanf("%lf", N) != EOF){
		med = N[0] * peso[0];
		for(i=1; i<4; i++){
			scanf("%lf", N+i);
			med += (N[i] * peso[i]);
		}
		med /= 10.0;
		printf("Media: %.1lf\n", med);
		
		if(med < 5.0)
			puts("Aluno reprovado.");
		else if(5.0 <= med && med < 7.0){
			puts("Aluno em exame.");
			scanf("%lf", &ex);
			printf("Nota do exame: %.1lf\n", ex);
			med += ex;
			med /= 2.0;
			if(med < 5.0) 
				puts("Aluno reprovado.");
			else
				puts("Aluno aprovado.");
			printf("Media final: %.1lf\n", med);
		}
		else if(7.0 <= med)
			puts("Aluno aprovado.");
	}
	return 0;
}
