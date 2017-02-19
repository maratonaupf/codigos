#include<stdio.h>

int main(void){
	int N;
	int s, b, a, s1, b1, a1, st, at, bt;
	double rs, rb, ra;
	scanf("%d", &N);
	s1 = b1 = a1 = st = at = bt = 0;
	while(N--){
		getchar();
		scanf("%*s");
		scanf("%d %d %d", &s, &b, &a);
		st += s; bt += b; at += a;
		scanf("%d %d %d", &s, &b, &a);
		s1 += s; b1 += b; a1 += a;
	}
	rs = 100.0 * (double) s1 / (double) st;
	rb = 100.0 * (double) b1 / (double) bt;
	ra = 100.0 * (double) a1 / (double) at;
	printf("Pontos de Saque: %.2lf %%.\n", rs);
	printf("Pontos de Bloqueio: %.2lf %%.\n", rb);
	printf("Pontos de Ataque: %.2lf %%.\n", ra);
	return 0;
}
