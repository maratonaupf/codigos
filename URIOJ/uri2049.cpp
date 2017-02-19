#include<stdio.h>
#include<string.h>
#define MAX 312345

int main(void){
	int test = 0;
	char s[8];
	char panel[MAX];
	while(scanf("%s", s), strcmp(s,"0")){
		scanf("%s", panel);
		if(test) printf("\n");
		printf("Instancia %d\n", ++test);
		printf("%s\n", strstr(panel, s) == NULL ? "falsa" : "verdadeira");
	}
	return 0;
}
