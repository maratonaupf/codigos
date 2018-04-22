/*
 * Leonardo Deliyannis Constantin
 * CodeForces 879A - Borya's Diagnosis
*/

#include <stdio.h>

int main(){
	int N, i, s, d, ans;
	while(scanf("%d", &N) != EOF){
		ans = -1;
		for(i = 1; i <= N; i++){
			scanf("%d %d", &s, &d);
			if(ans == -1){
				ans = s;
			}
			else{
				while(s <= ans){
					s += d;
				}
				ans = s;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
