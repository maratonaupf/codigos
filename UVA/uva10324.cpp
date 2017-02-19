#include<stdio.h>
#define MAX 1123456

void troque(int &a, int &b){ int c = a; a = b; b = c; }

int main(void){
	int N, a, b, tc = 0;
	int v[MAX];
	char s[MAX];
	while(fgets(s, MAX, stdin) != NULL && s[0] != '\n'){
		v[0] = 0;
		for(int i = 1; s[i] != '\n'; i++){
			v[i] = v[i-1] + (s[i] != s[i-1]);
		}
		scanf("%d", &N);
		printf("Case %d:\n", ++tc);
		while(N--){
			scanf("%d %d\n", &a, &b);
			printf("%s\n", v[a] == v[b] ? "Yes" : "No");
		}
	}
	return 0;
}
