/*
 * Leonardo Deliyannis Constantin
 * UVa 10783 - Odd Sum
*/

#include <stdio.h>

inline int rsq(int a){
	if(a == 0) return 0;
	a = (a + (a&1)) / 2;
	return a*a;
}

inline int rsq(int a, int b){
	return rsq(b) - (a <= 1 ? 0 : rsq(a-1));
}

int main(){
	int T, a, b, c;
	scanf("%d", &T);
	for(c = 1; c <= T; c++){
		scanf("%d %d", &a, &b);
		printf("Case %d: %d\n", c, rsq(a, b));
	}
	return 0;
}
