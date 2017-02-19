#include<stdio.h>
// algoritmo de troca usando XOR
#define troque(a, b) do{ a^=b; b^=a; a^=b; }while(0)

int knights(int M, int N){
	if(M > N) troque(M, N);
	if(M == 1) return M * N;
	if(M == 2) return N / 4 * 4 + (N % 4 == 1 ? 2 : N % 4 >= 2 ? 4 : 0);
	return M * N / 2 + ((M*N) % 2);
}

int main(void){
	int M, N;
	while(scanf("%d %d", &M, &N), M != 0 && N != 0){
		printf("%d knights may be placed on a %d row %d column board.\n",
				knights(M, N), M, N);
	}
	return 0;
}
