#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAX 1123
#include<algorithm>
using namespace std;
typedef long long ll;

int X, Y, P;
ll bit[MAX][MAX];

void atl_freq(int a, int b, ll val){
	int i, j;
	for(i=a+1; i<=X; i+= i&-i)
		for(j=b+1; j<=Y; j+= j&-j)
			bit[i][j]+=val;
}

ll fac(int a, int b){
	int ret=0, i, j;
	for(i=a; i>0; i-= i&-i)
		for(j=b; j>0; j-= j&-j)
			ret+=bit[i][j];
	return ret;
}

int freq_ac(int x, int y, int z, int w){
	int X1=max(x, z), X2=min(x, z),
		Y1=max(y, w), Y2=min(y, w);
	return fac(X1, Y1) - fac(X2-1, Y1) - (fac(X1, Y2-1)- fac(X2-1, Y2-1));
}

int main(){
	int Q, x, y, z, w;
	char c;
	ll n, qt;
	while(scanf("%d %d %d\n", &X, &Y, &P), X || Y || P){
		memset(bit, 0, sizeof(bit));
		scanf("%d\n", &Q);
		while(Q--){ 
			do { c=getchar(); } while (c!='A' && c!='P');
			if(c=='A'){ scanf(" %lld %d %d", &n, &x, &y);
				atl_freq(x, y, +n);
			}else{ scanf(" %d %d %d %d", &x, &y, &z, &w);
				qt=freq_ac(x+1, y+1, z+1, w+1);
				qt*=(ll)P;
				printf("%lld\n", qt);
			}
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}
