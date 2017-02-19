#include<stdio.h>
#define MAX 13
#define FOR(it, b, e) for((it) = (b); (it) != (e); (it)++)

int main(void){
	int N, v[MAX], i, first = 1;
	int a, b, c, d, e, f;
	while(scanf("%d", &N), N != 0){
		(first) ? first = 0 : printf("\n");
		for(i = 0; i < N; i++) scanf("%d", v+i);
		FOR(a, 0, N-5)
		  FOR(b, a+1, N-4)
		    FOR(c, b+1, N-3)
		      FOR(d, c+1, N-2)
		        FOR(e, d+1, N-1)
		          FOR(f, e+1, N)
					printf("%d %d %d %d %d %d\n", 
						v[a], v[b], v[c], v[d], v[e], v[f]);
	}
	return 0;
}
