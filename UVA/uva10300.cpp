#include<stdio.h>

int main(void){
	int n, f, val;
	int sp, ef;
	scanf("%d", &n);
	while(n--){
		val = 0;
		scanf("%d", &f);
		while(f--){
			scanf("%d %*d %d", &sp, &ef);
			val += ef*sp;
		}
		printf("%d\n", val);
	}
	return 0;
}
