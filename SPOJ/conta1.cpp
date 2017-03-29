#include<stdio.h>

int main(void){
	int N, conta;
	// while(cin >> N){
	while(scanf("%d", &N) != EOF){
		conta = 7;
		if(N > 100){
			conta += (N-100) * 5;
			N = 100;
		}
		if(N > 30){
			conta += (N-30) * 2;
			N = 30;
		}
		if(N > 10){
			conta += N-10;
		}
		// cout << conta << endl;
		printf("%d\n", conta);
	}
	return 0;
}
