#include<stdio.h>

int ia, ib, fa, fb;

int sim(){
	return (ia != fa) ? 1 : (ib != fb) ? 2 : 0;
	//~ if(ia != fa && ib != fb) return 1;
	//~ if(ia == fa && ib != fb) return 2;
	//~ if(ia != fa && ib == fb) return 1;
	//~ if(ia == fa && ib == fb) return 0;
}

int main(void){
	while(scanf("%d %d %d %d", &ia, &ib, &fa, &fb) != EOF){
		printf("%d\n", sim());
	}
	return 0;
}
