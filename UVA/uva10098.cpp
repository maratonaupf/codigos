/*
 * Leonardo Deliyannis Constantin
 * UVa 10098 - Generating Fast
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 11

int main(){
	int T, tam;
	char s[MAX];
	scanf("%d\n", &T);
	while(T--){
		fgets(s, MAX, stdin);
		s[tam = strlen(s)-1] = 0;
		sort(s, s+tam);
		do{
			printf("%s\n", s);
		}while(next_permutation(s, s+tam));
		printf("\n");
	}
	return 0;
}
