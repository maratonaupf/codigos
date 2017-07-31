/*
 * Leonardo Deliyannis Constantin
 * UVa 11835 - The Da Vinci Code
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
#define MAX 112

typedef unsigned ui;

vector<int> f;

void generate(){
	const ui UPPER_BOUND = 2147483647;
	int tam = 2;
	f = { 1, 2 };
	while((ui)f[tam-2] + (ui)f[tam-1] < UPPER_BOUND){
		f.push_back(f[tam-2] + f[tam-1]);
		tam++;
	}
}

int pos(int x){
	return (int) (lower_bound(f.begin(), f.end(), x) - f.begin());
}

int main(){
	int T, N, i, last, c;
	int p[MAX];
	char s[MAX], t[MAX];
	generate();
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		last = 0;
		for(i = 0; i < N; i++){
			scanf("%d ", &p[i]);
			p[i] = pos(p[i]);
			last = max(last, p[i]);
		}
		fgets(s, MAX, stdin);
		memset(t, ' ', sizeof(t));
		c = 0;
		for(i = 0; s[i] != '\n'; i++){
			if(c < N && isalpha(s[i]) && isupper(s[i])){
				t[p[c++]] = s[i];
			}
		}
		t[last+1] = 0;
		printf("%s\n", t);
	}
	f.clear();
	return 0;
}
