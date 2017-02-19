#include<stdio.h>
#include<string.h>
#define MAX 1123456

int digitsOf(int n){
	int ret = 0;
	while(n > 0){
		ret++;
		n /= 10;
	}
	return ret;
}

int f(char *s){
	int i = 1, y, x = strlen(s)-1;
	s[x] = 0;
	if(strcmp(s, "1") == 0) return 1;
	while(1){
		i++;
		y = x;
		x = digitsOf(x);
		if(x == y) break;
	}
	return i;
}

int main(void){
	char s[MAX];
	while(fgets(s, MAX, stdin), strcmp(s, "END\n")){
		printf("%d\n", f(s));
	}
	return 0;
}
