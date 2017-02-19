#include<stdio.h>
#include<string.h>
#define MAX 11

int idx(int N, char v[][16], char *s){
	int i;
	for(i = 0; i < N; i++)
		if(strcmp(s, v[i]) == 0) return i;
	return -1;
}

int main(void){
	int N, m[MAX], i, j, money, g;
	bool first = true;
	char v[MAX][16], s[16];
	while(scanf("%d", &N) != EOF){
		if(first) first = false;
		else printf("\n");
		for(i = 0; i < N; i++){ 
			scanf("%s", v[i]);
			m[i] = 0;
		}
		for(i = 0; i < N; i++){
			scanf("%s %d %d", s, &money, &g);
			if(g) m[idx(N, v, s)] -= (money/g) * g;
			for(j = 0; j < g; j++){
				scanf("%s", s);
				m[idx(N, v, s)] += money/g;
			}
		}
		for(i = 0; i < N; i++){
			printf("%s %d\n", v[i], m[i]);
		}
	}
	return 0;
}
