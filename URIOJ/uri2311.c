#include<stdio.h>
#define MAX 112

int main(void){
	int N, i, menor, maior;
	double n[7], gd, nf;
	char s[MAX];
	scanf("%d", &N);
	while(N--){
		getchar();
		scanf("%s", s);
		scanf("%lf", &gd);
		menor = maior = 0;
		for(i = 0; i < 7; i++){
			scanf("%lf", n+i);
			if(n[i] < n[menor]) menor = i;
			if(n[i] > n[maior]) maior = i;
		}
		nf = n[menor] = n[maior] = 0.0;
		for(i = 0; i < 7; i++) nf += n[i];
		nf *= gd;
		printf("%s %.2lf\n", s, nf);
	}
	return 0;
}
