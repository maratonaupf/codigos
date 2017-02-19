#include<stdio.h>

int main(void){
	int N, val, acc = 0;
	char s[10];
	scanf("%d\n", &N);
	while(N--){
		scanf("%s", s);
		if(s[0] == 'd'){
			scanf("%d", &val);
			acc += val;
		} else printf("%d\n", acc);
	}
	return 0;
}
