/*
 * Leonardo Deliyannis Constantin
 * OBI 2017 - Palíndromos
 * Implementação usando PD Top-Down (original por Guilherme)
 */

#include <stdio.h>
#include <vector>
using namespace std;
#define MAX 2123

typedef vector<int> vi;

int N;
char s[MAX];

vector<vi> p;
vi pd;

int isPalindrome(int a, int b){
	if(p[a][b] != -1) return p[a][b];
	if(a == b) return p[a][b] = 1;
	if(a == b-1) return p[a][b] = (s[a] == s[b]);
	if(s[a] != s[b]) return p[a][b] = 0;
	return p[a][b] = isPalindrome(a+1, b-1);
}

int partitions(int k){
	int menor = MAX, i, val;
	if(pd[k] != -1) return pd[k];
	if(isPalindrome(0, k)) return pd[k] = 1;
	for(i = k; i > 0; i--){
		if(isPalindrome(i, k)){
			val = partitions(i-1);
			if(val+1 < menor) menor = val+1;
		}
	}
	return pd[k] = menor;
}

int main(){
	while(scanf("%d\n", &N) != EOF){
		fgets(s, MAX, stdin);
		s[N] = 0;
		p.assign(N, vi(N, -1));
		pd.assign(N, -1);
		printf("%d\n", partitions(N-1));
	}
	return 0;
}
