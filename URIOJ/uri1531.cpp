#include<stdio.h>
#include<string.h>
#define MSET(arr,val) memset(arr,val,sizeof(arr)) 
#define MAX 1123456
 
typedef long long ll;
typedef struct _tuple{
    ll a;
    ll b;
} ii;
 
ii fastDoubling(ll N, ll mod) {
    ii ret;
    ii aux;
    if(N == 0){
        ret.a = 0;
        ret.b = 1;
    }
    else if(N == 1 || N == 2){ 
        ret.a = 1;
        ret.b = N;
    }
    else{
        aux = fastDoubling(N/2, mod); 
         
        ret.a = (aux.a * (aux.b * 2 + mod - aux.a)) % mod;
        ret.b = (aux.a * aux.a + aux.b * aux.b) % mod;
         
        if(N%2 != 0) { 
            ll aux2 = ret.a;
            ret.a = ret.b;
            ret.b = (aux2 + ret.b) % mod;
        }
    }
    return ret;
}
 
int hasCycle[MAX];
int cycle[MAX];

ll cycleSize(ll M){
	ll X, a, b, c;
	a = 1;
	b = 1;
	for(X = 3; !hasCycle[M]; X++){
		c = (a + b) % M;
		if(c == b && c == 1){
			cycle[M] = X-2;
			hasCycle[M] = 1;
		}
		a = b;
		b = c;
	}
	return cycle[M];
}

int main(void){
	ll N, M;
	ll C;
	ll resp;
	MSET(hasCycle, 0);
	while(scanf("%lld %lld", &N, &M) != EOF){
		C = cycleSize(M);
		resp = fastDoubling(N, C).a;
		resp = fastDoubling(resp, M).a;
		printf("%lld\n", resp);
	}
	return 0;
}