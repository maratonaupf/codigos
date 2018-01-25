/*
 * Leonardo Deliyannis Constantin
 * UVa 278 - Chess
 */

#include <stdio.h>
#include <algorithm>
using namespace std;

inline int knights(int n, int m){
	return n*m / 2 + (n&1 && m&1);
}

inline int kings(int n, int m){
	if(n&1) n++;
	if(m&1) m++;
	return (n/2) * (m/2);
}

int main(){
	int T, n, m;
	char p;
	scanf("%d\n", &T);
	while(T--){
		scanf("%c %d %d\n", &p, &n, &m);
		printf("%d\n", p == 'k' ? knights(n, m) : 
			p == 'K' ? kings(n, m) : min(n, m));
	}
	return 0;
}
