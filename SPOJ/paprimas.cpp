#include<stdio.h>
#include<vector>
using namespace std;
#define LEN 22
#define MAX 1123

int charToInt(char c){
	return ('a' <= c && c <= 'z') ? 1 + c - 'a' : 27 + c - 'A';
}

int strToInt(const char *s){
	int i, ret = 0;
	for(i = 0; s[i]; i++){
		ret += charToInt(s[i]);
	}
	return ret;
}

vector<bool> isPrime;

void sieve(int limit){
	int i, j;
	isPrime.assign(limit+1, true);
	isPrime[0] = isPrime[1] = false;
	for(i = 2; i <= limit; i++) 
		if(isPrime[i])
			for(j = i*i; j <= limit; j += i) 
				isPrime[j] = false;
	isPrime[1] = true;
}

int main(void){
	char s[LEN];
	sieve(MAX);
	while(scanf("%s\n", s) != EOF){
		printf("It is%s a prime word.\n", isPrime[strToInt(s)] ? "" : " not");
	}
	return 0;
}
