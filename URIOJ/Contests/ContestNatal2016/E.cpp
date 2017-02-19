#include<stdio.h>
#include<ctype.h>
#include<string>
#include<map>
#include<set>
#define TAM 512
using namespace std;

int main(void){
	int X, i;
	char n[TAM], p[TAM];
	scanf("%d\n", &X);
	map<string, set<string> > m;
	while(X--){
		scanf("%s", n);
		for(i = 0; i < 3; i++){
			scanf(" %s", p);
			m[(string)n].insert((string)p);
		}
	}
	while(scanf("\n%s", n) != EOF){
		scanf(" %s", p);
		if(m[(string)n].count((string)p) == 0)
			puts("Tente Novamente!");
		else puts("Uhul! Seu amigo secreto vai adorar o/");
	}
	m.clear();
	return 0;
}
