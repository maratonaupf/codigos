#include<stdio.h>
#include<math.h>

int f(int N){
	return (N - (1 << ((int) (log(N)/log(2.0)) ) )) * 2 + 1;
}

int toInt(char *s){
	int N, zeros = s[3] - '0';
	N = (s[0] - '0') * 10;
	N += (s[1] - '0');
	while(zeros--){
		N *= 10;
	}
	return N;
}

int main(void){
	char s[6];
	int N;
	while(fgets(s, 6, stdin), N = toInt(s)){
		printf("%d\n", f(N));
	}
	return 0;
}
