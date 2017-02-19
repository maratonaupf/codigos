#include<stdio.h>

int expbin(int a, int n){
	int aux;
	if(n == 0) return 1;
	aux = 1;
	while(n > 1){
		if(n&1) aux *= a;
		a *= a;
		n /= 2;
	}
	return a * aux;
}

int main(void){
	int T, c, d, ans;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &c, &d);
		ans = expbin(26, c) * expbin(10, d);
		printf("%d\n", (ans > 1) ? ans : 0);
	}
	return 0;
}
