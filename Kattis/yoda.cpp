/*
 * Leonardo Deliyannis Constantin
 * https://open.kattis.com/problems/yoda
*/

#include <stdio.h>
#include <string.h>
#include <utility>
using namespace std;
#define LEN 11

typedef pair<int, int> ii;

void drag(char *a, int m, int n){
	memcpy(a + (n-m), a, m * sizeof(char));
	for(int i = 0; i < (n-m); i++) a[i] = '0';
	a[n] = '\0';
}

int fromString(char *s){
	int ret = -1;
	for(int i = 0; s[i]; i++){
		if(s[i] == ' ')
			continue;
		else if(ret == -1) 
			ret = 0;
		ret *= 10;
		ret += s[i] - '0';
	}
	return ret;
}

ii solve(char *a, char *b){
	int m = strlen(a), n = strlen(b);
	if(m < n) drag(a, m, n);
	if(m > n) drag(b, n, m);
	for(int i = 0; a[i]; i++){
		if(a[i] < b[i]) a[i] = ' ';
		if(a[i] > b[i]) b[i] = ' ';
	}
	return {fromString(a), fromString(b)};
}

int main(){
	char a[LEN], b[LEN];
	while(scanf("%s", a) != EOF){
		scanf("%s", b);
		ii ans = solve(a, b);
		(ans.first  != -1) ? 
			printf("%d\n", ans.first ) : 
			printf("YODA\n");
		(ans.second != -1) ? 
			printf("%d\n", ans.second) : 
			printf("YODA\n");
	}
	return 0;
}
