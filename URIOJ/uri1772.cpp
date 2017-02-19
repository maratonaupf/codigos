#include<cstdio>

int main(void){	
	unsigned N, K, A, B, bit1, bit2, 
		top, bot;
	while(scanf("%u %u\n", &N, &K), K){
		top = bot = N;
		while(K--){ scanf("%u %u\n", &A, &B);
			bit1 = (N >> A) & 1;
			bit2 = (N >> B) & 1;
			
			if(bit1) N |= (bit1 << B);
			else N &= ~(1 << B);
			
			if(bit2) N |= (bit2 << A);
			else N &= ~(1 << A);
			
			if(top < N) top = N;
			if(bot > N) bot = N;
		}
		printf("%u %u %u\n", N, top, bot);
	}
	return 0;
}
