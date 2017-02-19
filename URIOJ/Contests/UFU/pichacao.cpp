#include<stdio.h>
#include<string.h>
#include<ctype.h>
//#define DEBP

typedef unsigned long long ull;

int main(void){
	int T;
	ull N;
	char l[55];
	char s[55];
	scanf("%d", &T);
	while(T--){
		scanf("%s %lld", l, &N);
		ull digits = 1;
		ull tam = strlen(l);
		ull pot = tam;
		N--;
		while(N > pot){
			N -= pot;
			pot *= tam;
			digits++;
		}
		
		for(int i = digits - 1; i >= 0 ; i--){
			s[i] = l[N % tam];
			N /= tam;
		}
		
		s[digits] = 0;

		puts(s);
	}
	return 0;
}
