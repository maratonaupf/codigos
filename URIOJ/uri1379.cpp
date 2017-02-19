#include<cstdio>

typedef long long ll;

int main(void){	
	ll A, B;
	while(scanf("%lld %lld", &A, &B), A){
		printf("%lld\n", (A << 1) - B);
	}
	return 0;
}
