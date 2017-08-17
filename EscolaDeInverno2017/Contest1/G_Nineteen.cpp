/*
 * Leonardo Deliyannis Constantin
 * G - Nineteen
 */

#include <stdio.h>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define MAX 112

int min4(int a, int b, int c, int d){
	return min(min(a, b), min(c, d));
}

int main(){
	int i;
	char s[MAX];
	unordered_map<char, int> c;
	while(fgets(s, MAX, stdin) != NULL){
		for(i = 0; s[i] != '\n'; i++){
			c[s[i]]++;
		}
		printf("%d\n", min4((c['n']-1)/2, c['i'], c['e']/3, c['t']));
		c.clear();
	}
	return 0;
}
