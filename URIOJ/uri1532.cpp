#include<cstdio>

int main(void){	
	int N, V, v, pos, cur;
	while(scanf("%d %d\n", &N, &V), N){
		do{
			v = V;
			pos = 0;
			cur = v;
			while(pos < N){
				if(!v) break;
				pos+=v;
				cur--;
				if(!cur){ v--; cur = v; }
			}
			V--;
		}while(pos!=N && V);
		printf("%spossivel\n", pos==N ? "" : "im");
	}
	return 0;
}
