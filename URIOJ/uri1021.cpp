#include<cstdio>

int NT[6] = {2, 5, 10, 20, 50, 100},
	MD[6] = {1, 5, 10, 25, 50, 100};

int main(void){	
	double val;
	int i, iv, qt;
	while(scanf("%lf", &val) != EOF){
		iv = val;
		puts("NOTAS:");
		for(i = 5; i+1; i--){
			qt = iv / NT[i];
			iv %= NT[i];
			printf("%d nota(s) de R$ %.2lf\n", qt, (double) NT[i]);
		}
		iv = val - iv;
		val -= (double) iv;
		iv = val * 100.0;
		puts("MOEDAS:");
		for(i = 5; i+1; i--){
			qt = iv / MD[i];
			iv %= MD[i];
			printf("%d moeda(s) de R$ %.2lf\n", qt, ((double) MD[i]) / 100.0);
		}
	}
	return 0;
}
