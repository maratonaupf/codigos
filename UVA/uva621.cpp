#include<stdio.h>
#include<string.h>
#define MAX 112345
#define eq(a, b) (strcmp((a), (b)) == 0)

char result(char *s){
	int tam = strlen(s) - 1;
	s[tam] = 0;
	if(eq(s, "1") || eq(s, "4") || eq(s, "78")) return '+';
	if(s[tam-2] == '3' && s[tam-1] == '5') return '-';
	if(s[0] == '9' && s[tam-1] == '4') return '*';
	return '?';
}

int main(void){
	int N;
	char s[MAX];
	scanf("%d\n", &N);
	while(N--){
		fgets(s, MAX, stdin);
		printf("%c\n", result(s));
	}
	return 0;
}
