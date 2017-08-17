/*
 * Leonardo Deliyannis Constantin
 * A - Jumps
 */

#include <stdio.h>
#define MAX 212345

int gcd(int a, int b){
	int c;
	while(b != 0){
		c = a;
		a = b;
		b = c%b;
	}
	return a;
}

int main(){
	int N, X, i, resp;
	int a[MAX];
	while(scanf("%d %d", &N, &X) != EOF){
		scanf("%d", &resp);
		for(i = 1; i < N; i++){
			scanf("%d", &a[i]);
			resp = gcd(resp, a[i]);
		}
		printf("%s\n", (X % resp == 0) ? "YES" : "NO");
	}
	return 0;
}
