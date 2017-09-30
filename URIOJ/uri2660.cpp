/*
 * Leonardo Deliyannis Constantin
 * URI 2660 - Cigarras Periódicas (Maratona SBC 2017)
 */

#include <stdio.h>
#define MAX 112345

typedef long long ll;

ll gcd(int a, int b){
	int c;
	while(b != 0){
		c = a;
		a = b;
		b = c%b;
	}
	return a;
}

inline ll lcm(int a, int b){
	return a / gcd(a, b) * b;
}

int main(){
	int N, L;
	int c[MAX];
	int i, resp;
	ll aux, t, acum;
	while(scanf("%d %d", &N, &L) != EOF){
		for(i = 0; i < N; i++){
			scanf("%d", &c[i]);
			acum = (i > 0) ? lcm(acum, c[i]) : c[i];
		}
		resp = t = -1;
		for(i = 1; i <= L; i++){
			aux = lcm(i, acum);
			if(t < aux && aux <= L){
				resp = i;
				t = aux;
			}
		}
		printf("%d\n", resp);
	}
	return 0;
}
