#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define LEN 8
//#define DEBP
#ifdef DEBP
#include<assert.h>
#endif

int exp(int a, int n){
	if(n == 0) return 1;
	int b = 1;
	while(n > 1){
		if(n&1) b *= a;
		a *= a;
		n >>= 1; // same as n /= 2;
	}
	return a * b;
}

int toInt(char c){
	return (isdigit(c)) ? c - '0' : 10 + c - 'A';
}

char toChar(int n){
	return (0 <= n && n <= 9) ? n + '0' : n-10 + 'A';
}

int toBase10(const char *s){
	int i, ret = 0;
	int tam = strlen(s);
	for(i = tam-1; i >= 0; i--){
		ret += toInt(s[i]) * exp(36, (tam-1) - i);
	}
	return ret;
}

void toBase36(char *dest, int n){
	int tam = 0;
	while(n > 0){
		memmove(dest+1, dest, tam);
		dest[0] = toChar(n%36);
		n /= 36;
		tam++;
	}
	dest[tam] = '\0';
}

int main(void){
	char a[LEN], b[LEN];
	char s[LEN];
	#ifdef DEBP
	assert(toBase10("BANANA") == 683010982);
	toBase36(s, 683010982);
	assert(strcmp(s, "BANANA") == 0);
	#endif
	while(scanf("%s %s\n", a, b), strcmp(a, "0") != 0 && strcmp(b, "0") != 0){
		toBase36(s, toBase10(a) + toBase10(b));
		printf("%s\n", s);
	}
	return 0;
}
