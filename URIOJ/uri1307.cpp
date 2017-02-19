#include<stdio.h>
#include<string.h>
//#define DEBP // DEBug Print;

int valueOf(char* s){
	int ret = 0;
	int tam = strlen(s) - 1;
	for(int i = 0; i <= tam; i++){
		ret += (s[i] - '0') << (tam - i);
	}
	return ret;
}

int gcd(int a, int b){
	int c;
	while(b != 0){
		c = a;
		a = b;
		b = c % b;
	}
	return a;
}

/* song by Whitesnake */
bool isThisLove(char* s1, char* s2){
	int v1 = valueOf(s1);
	int v2 = valueOf(s2);
	return gcd(v1, v2) != 1;
}

int main(void){
	int N, test;
	bool ans;
	char s1[40], s2[40];
	
	scanf("%d", &N);
	for(test = 1; test <= N; test++){
		scanf("%s", s1);
		scanf("%s", s2);
		ans = isThisLove(s1, s2);
		printf("Pair #%d: %s!\n", test, ans ? 
				"All you need is love" : "Love is not all you need");
	}
	return 0;
}
