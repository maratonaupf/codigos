#include<stdio.h>

int mile(int n){
	return (n/30 + 1) * 10; 
}

int juice(int n){
	return (n/60 + 1) * 15; 
}

int main(void){
	int T, tc = 0, val;
	int N, c, m, j;
	scanf("%d", &T);
	while(tc < T){
		scanf("%d", &N);
		m = j = 0;
		while(N--){
			scanf("%d", &c);
			m += mile(c);
			j += juice(c);
		}
		val = (m < j) ? m : j;
		printf("Case %d: %s %d\n", ++tc, 
			(m < j) ? "Mile" : (m > j) ? "Juice" : "Mile Juice", val);
	}
	return 0;
}
