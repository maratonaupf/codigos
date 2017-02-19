#include<cstdio>
#include<cstring>
#define MSET(q,w) memset(q, w, sizeof(q))
#define MAX 1123
#define P 1000000007
/* fine P 1123456789 */

typedef unsigned long long ull;

ull fat(ull n){
	if(n == 0) return 1;
	return n * fat(n - 1) % P;
}

ull expbin(ull a, ull b){
	ull y;
	if(b==0) return 1;
	if(b&1) return a * expbin(a, b-1) % P;
	y = expbin(a, b >> 1);
	return y*y % P;
}

int main(void){	
	char str[MAX];
	int oc[26], i;
	ull num, den;
	
	while(fgets(str, MAX, stdin)){
		num = fat(strlen(str) - 1);
		MSET(oc, 0);
		
		for(i = 0; str[i] != '\n'; i++)
			oc[str[i] - 'A']++;
		den = 1;
		for(i = 0; i < 26; i++)
			den = den * fat(oc[i]) % P;
		printf("%llu\n", num * expbin(den, P - 2) % P);
	}
	return 0;
}
