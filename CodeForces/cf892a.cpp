/*
 * Leonardo Deliyannis Constantin
 * CodeForces 892A - Greed
*/

#include <stdio.h>
#include <algorithm>

typedef long long ll;

int main(){
	int N, i, a, b;
	ll sum, b1, b2;
	while(scanf("%d", &N) != EOF){
		sum = 0;
		for(i = 0; i < N; i++){
			scanf("%d", &a);
			sum += (ll)a;
		}
		b1 = b2 = 0LL;
		for(i = 0; i < N; i++){
			scanf("%d", &b);
			if(b1 <= b){
				b2 = b1;
				b1 = (ll)b;
			}
			else if (b2 <= b){
				b2 = (ll)b;
			}
		}
		printf("%s\n", sum <= b1+b2 ? "YES" : "NO");
	}
	return 0;
}
