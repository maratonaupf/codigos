#include<stdio.h>

int mdc(int a, int b) {
	if(b == 0) return a;
	return mdc(b, a%b);
}

int main() {
	int num, den, apostas[100], cont = -1;
	while(scanf("%d %d", &num, &den) != EOF) {
		 apostas[++cont] = mdc(num, den);
		 puts(apostas[cont] > 5 ? "Noel" : "Gnomos");
	}
	for (int i = cont; i >= 0; i--) {
		printf("%d ", apostas[i]);
	}
	printf("\n");
	return 0;
}
