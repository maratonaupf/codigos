#include<stdio.h>
#define MAX 11

int valueOf(char *s){
	int i, j, v[3], idx = 0;
	v[0] = v[1] = v[2] = 0;
	const char l[][6] = {"one", "two", "three"};
	for(i = 0; s[i]; i++){
		for(j = 0; j < 3; j++){
			v[j] += s[i] == l[j][i];
			if(v[j] > v[idx]) idx = j;
		}
	}
	return idx+1;
}

int main(void){
	int n;
	char s[MAX];
	scanf("%d", &n);
	while(n--){
		scanf("%s", s);
		printf("%d\n", valueOf(s));
	}
	return 0;
}
