#include<stdio.h>
#define MAX 1123

int main(void){
	int T, n, a[MAX], b;
	int i, j;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		b = 0;
		for(i = 0; i < n; i++){
			scanf("%d", a+i);
			for(j = 0; j < i; j++){
				if(a[j] <= a[i]) b++;
			}
		}
		printf("%d\n", b);
	}
	return 0;
}
