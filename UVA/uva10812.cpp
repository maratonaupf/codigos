#include<stdio.h>
#include<stdlib.h>
#define min(a, b) ((a < b) ? a : b) 
#define max(a, b) ((a > b) ? a : b) 

int main(void){
	int N, s, d, p1, p2;
	scanf("%d", &N);
	while(N--){
		scanf("%d %d", &s, &d);
		p1 = abs(s-d) / 2; 
		p2 = s - p1;
		if(p1 + p2 == s && abs(p1-p2) == d) 
			printf("%d %d\n", max(p1, p2), min(p1, p2));
		else printf("impossible\n");
	}
	return 0;
}
