#include <stdio.h>
#include <stdlib.h>

int fx(int n){
	int c=1;
	while(n>1){
		if(n%2!=0) n=(3*n)+1;
		else n/=2;
		c++;
	}
	return c;
}

void xchg(int &a, int &b){
	int aux=a;
	a=b;
	b=aux;
}

int main(){
	int a, b;
	while(scanf("%d %d", &a, &b)!=EOF){
		int x=0, i, tmp;
		printf("%d %d ", a, b);
		if(a>b) xchg(a, b);
		for(i=a; i<=b; i++){
			tmp=fx(i);
			if(x < tmp) x=tmp;
		}
		printf("%d\n", x);
	}
	return EXIT_SUCCESS;
}
