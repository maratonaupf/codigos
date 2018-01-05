/*
 * Leonardo Deliyannis Constantin
 * UVa 278 - Chess
 */

#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
#define isEven(x) (!((x)&1))

inline int knights(int a, int b){
	return (a * b) / 2 + ((a&1) && (b&1)); }

inline int kings(int a, int b){
	return ((a-isEven(a))/2 + 1) * ((b-isEven(b))/2 + 1); }

int main(){
	int T, N, M;
	char p;
	scanf("%d\n", &T);
	while(T--){
		scanf("%c %d %d\n", &p, &N, &M);
		printf("%d\n", p == 'K' ? kings(N, M) :
			p == 'k' ? knights(N, M) : min(N, M));
	}
	return 0;
}
