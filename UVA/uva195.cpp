#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>
#include<map>
using namespace std;
#define MAX 112

map<char, int> tabela;

bool cmp(char a, char b){
	return tabela[a] < tabela[b];
}

void criaTabela(){
	int idx = 0;
	for(char c = 'A'; c <= 'Z'; c++){
		tabela[c] = idx++;
		tabela[tolower(c)] = idx++;
	}
}

int main(void){
	int N, tam;
	char s[MAX];
	criaTabela();
	scanf("%d\n", &N);
	while(N--){
		fgets(s, MAX, stdin);
		s[tam = strlen(s) - 1] = 0;
		sort(s, s+tam, cmp);
		do{
			printf("%s\n", s);
		}while(next_permutation(s, s+tam, cmp));
	}
	return 0;
}
