/*
 * Leonardo Deliyannis Constantin
 * URI 2670 - Máquina de Café (Maratona SBC 2017)
 */

#include <stdio.h>
#include <algorithm>
using namespace std;

inline int min(int x, int y, int z){
	return min(x, min(y, z));
}

inline int solve(int a, int b, int c){
	return min(a*4 + b*2, a*2 + c*2, b*2 + c*4);
}

int main(){
	int a, b, c;
	while(scanf("%d %d %d", &a, &b, &c) != EOF){
		printf("%d\n", solve(a, b, c));
	}
	return 0;
}
