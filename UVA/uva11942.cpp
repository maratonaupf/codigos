#include<stdio.h>

int main(void){
	int N, i, b4, curr, ord, rev;
	scanf("%d", &N);
	printf("Lumberjacks:\n");
	while(N--){
		ord = 1;
		rev = 1;
		scanf("%d", &b4);
		for(i = 1; i < 10; i++){
			scanf("%d", &curr);
			if(b4 > curr) ord = 0;
			if(b4 < curr) rev = 0;
			b4 = curr;
		}
		printf("%s\n", ord || rev ? "Ordered" : "Unordered");
	}
	return 0;
}
