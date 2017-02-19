#include<stdio.h>
#include<string.h>
#define MAX 112
#define LEFT -1
#define RIGHT -2

int readval(){
	int idx;
	scanf("%*s %d", &idx);
	return idx;
}

int main(void){
	int T, N, p, i, v[MAX];
	scanf("%d", &T);
	char s[10];
	while(T--){
		scanf("%d", &N);
		p = 0;
		memset(v, 0, sizeof(v));
		for(i = 1; i <= N; i++){
			getchar();
			scanf("%s", s);
			v[i] = (s[0] == 'L') ? LEFT : (s[0] == 'R') ? RIGHT : v[readval()];
			(v[i] == LEFT) ? p-- : p++;
		}
		printf("%d\n", p);
	}
	return 0;
}
