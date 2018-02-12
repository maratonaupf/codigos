/*
 * Leonardo Deliyannis Constantin
 * URI 1507 - Subsequências
 */

#include <stdio.h>
#include <string.h>
#define LEN 112345

char s[LEN];
char t[112];

bool isSubSeq(int m, int n){
	if(n == 0) return true;
	if(m == 0) return false;
	if(s[m-1] == t[n-1]){
		return isSubSeq(m-1, n-1);
	}
	return isSubSeq(m-1, n);
}

int main(){
	int N, Q;
	scanf("%d", &N);
	while(N--){
		scanf("%s", s);
		scanf("%d", &Q);
		while(Q--){
			scanf("%s", t);
			printf("%s\n", isSubSeq(strlen(s), strlen(t)) ? 
				"Yes" : "No");
		}
	}
	return 0;
}
