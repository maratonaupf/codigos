#include<stdio.h>
#include<string.h>
#define MAX 112345
//#define DEBP // DEBug Print

char v[41][MAX];

void galerito(){
	strcpy(v[0], "3");
	int cont, pos, j;
	char token;
	
	for(int i = 1; i <= 40; i++){
		pos = j = 0;
		while(v[i-1][j]){
			cont = 0; token = v[i-1][j];
			while(token == v[i-1][j]){
				cont++; j++;
			}
			v[i][pos++] = '0' + cont;
#ifdef DEBP
			printf("i: %d, POS: %d, TOKEN = '%c'\n", i, pos, token);
#endif
			v[i][pos++] = token;
		}
		v[i][pos] = '\0';
	}
}

int main(void){
	int N;
	galerito();
	while(scanf("%d", &N) != EOF){
		puts(v[N-1]);
	}
	return 0;
}
