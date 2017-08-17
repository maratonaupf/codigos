#include<stdio.h>
#include<map>
#include<algorithm>
#define MAX 112
using namespace std;

map<char, int> c;

int min4(int u, int v, int w, int x){
	return min(min(u, v), min(w, x));
}

int main(void){
	char s[MAX];
	while(fgets(s, MAX, stdin) != NULL){
		for(int i = 0; s[i] != '\n'; i++){
			c[s[i]]++;
		}
		printf("%d\n", min4(++c['n']/3, c['i'], c['t'], c['e']/3));
		c.clear();
	}
	return 0;
}
