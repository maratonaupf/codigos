/*
 * Leonardo Deliyannis Constantin
 * URI 2544 - Kage Bunshin no Jutsu
 */

#include <stdio.h>

int main(){
	int N, ans;
	while(scanf("%d", &N) != EOF){
		ans = 0;
		while(N > 1){
			N >>= 1;
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
