#include<stdio.h>
#define LEN 22
#define MAX 11234

typedef struct _node{
	char s[LEN];
	int l, h;
} maker;

int main(void){
	int T, D, Q, P;
	int i, idx, count;
	maker v[MAX];
	scanf("%d\n", &T);
	while(T--){
		scanf("%d\n", &D);
		for(i = 0; i < D; i++){
			scanf("%s %d %d\n", v[i].s, &v[i].l, &v[i].h);
		}
		scanf("%d", &Q);
		while(Q--){
			scanf("%d", &P);
			idx = -1; count = 0;
			for(i = 0; i < D; i++){
				if(v[i].l <= P && P <= v[i].h){
					idx = i;
					count++;
				}
			}
			printf("%s\n", (count == 1) ? v[idx].s : "UNDETERMINED");
		}
		if(T) printf("\n");
	}
	return 0;
}
