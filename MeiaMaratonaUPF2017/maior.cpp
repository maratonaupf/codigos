#include<stdio.h>

int main(){
	int N;
	int a, b, ca, cb;
	while(scanf("%d", &N), N != 0){
		ca = cb = 0;
		while(N--){
			scanf("%d %d", &a, &b);
			if(a > b) ca++;
			if(a < b) cb++;
		}
		printf("%d %d\n", ca, cb);
	}
	return 0;
}
