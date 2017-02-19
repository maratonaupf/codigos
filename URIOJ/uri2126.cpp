#include<stdio.h>
#include<string.h>
#define MAX 112

int subseq(char *n1, char *n2, int *last){
	int cont = 0;
	int tam = strlen(n1);
	char *s;
	while((s = strstr(n2, n1))){
		cont++;
		memset(s, 'X', tam);
		*last = s-n2 + 1;
	}
	return cont;
}

int main(void){
	int caso = 0, last, ans;
	char n1[MAX], n2[MAX];
	while(scanf("%s\n", n1) != EOF){
		scanf("%s\n", n2);
		ans = subseq(n1, n2, &last);
		printf("Caso #%d:\n", ++caso);
		if(ans){ 
			printf("Qtd.Subsequencias: %d\n", ans);
			printf("Pos: %d\n", last);
		}
		else puts("Nao existe subsequencia");
		putchar('\n');
	}
	return 0;
}
