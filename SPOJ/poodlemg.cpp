/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/POODLEMG/
 */

#include <stdio.h>
#define MAX 22

void makePoodle(char *s, int N){
	int i;
	N = (N < 6) ? 6 : (N > 20) ? 20 : N;
	s[0] = 'P';
	for(i = 1; i < N-3; i++) s[i] = 'o';
	s[N-3] = 'd';
	s[N-2] = 'l';
	s[N-1] = 'e';
	s[N] = 0;
}

int main(){
	int N, P;
	char s[MAX];
	while(scanf("%d %d", &N, &P), N != 0){
		makePoodle(s, N/P + (N%P ? 1 : 0));
		printf("%s\n", s);
	}
	return 0;
}
