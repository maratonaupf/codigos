/*
 * Leonardo Deliyannis Constantin
 * CodeForces 835A - Key races
 */

#include <stdio.h>

int main(){
	int s, v1, v2, t1, t2;
	int r1, r2;
	while(scanf("%d", &s) != EOF){
		scanf("%d %d %d %d", &v1, &v2, &t1, &t2);
		r1 = s*v1 + 2*t1;
		r2 = s*v2 + 2*t2;
		printf("%s\n", r1 < r2 ? "First" :
			r1 > r2 ? "Second" : "Friendship");
	}
	return 0;
}
