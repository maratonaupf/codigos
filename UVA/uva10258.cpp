#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 112

typedef struct _contestant{
	int solved, penalty, number;
	int sub[10], sol[10];
} contestant;

int cmp(const void *p1, const void *p2){
	contestant a = *(contestant*)p1;
	contestant b = *(contestant*)p2;
	if(a.solved != b.solved) return b.solved - a.solved;
	if(a.penalty != b.penalty) return a.penalty - b.penalty;
	return a.number - b.number;
}

int main(void){
	int T;
	int c, p, t;
	char L, s[MAX];
	contestant v[MAX];
	scanf("%d\n\n", &T);
	while(T--){
		memset(v, 0, sizeof(v));
		for(c = 0; c < MAX; c++) v[c].number = MAX;
		while(fgets(s, MAX, stdin) != NULL && strcmp("\n", s)){
			sscanf(s, "%d %d %d %c", &c, &p, &t, &L);
			v[c].number = c;
			if(L == 'I') v[c].sub[p]++;
			if(L == 'C' && v[c].sol[p] == 0){
				v[c].sol[p] = 1;
				v[c].solved++;
				v[c].penalty += t + (v[c].sub[p]*20);
			}
		}
		qsort(v, MAX, sizeof(v[0]), &cmp);
		for(c = 0; v[c].number != MAX; c++){
			printf("%d %d %d\n", v[c].number, v[c].solved, v[c].penalty);
		}
		if(T) printf("\n");
	}
	return 0;
}
