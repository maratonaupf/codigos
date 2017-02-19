#include<stdio.h>
#define MAX 112

int main(void){
	int T, i, tc = 0;
	char s[10][MAX];
	int r[10], top;
	scanf("%d\n", &T);
	while(tc < T){
		top = -1;
		for(i = 0; i < 10; i++){
			scanf("%s %d\n", s[i], r+i);
			if(top < r[i]) top = r[i];
		}
		printf("Case #%d:\n", ++tc);
		for(i = 0; i < 10; i++){
			if(r[i] == top){
				puts(s[i]);
			}
		}
	}
	return 0;
}
