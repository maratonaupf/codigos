/*
 * Leonardo Deliyannis Constantin
 * UVa 941 - Permutations
*/

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define MAX 21

typedef unsigned long long ull;

ull _f[MAX];
void precalc(){
	_f[0] = 1ULL;
	for(int i = 1; i <= 20; i++){
		_f[i] = _f[i-1] * (ull)i;
	}
}
inline ull fat(int N){ return _f[N]; }

string permute(string s, ull k){
	string p = "";
	ull f;
	int i;
	while(!s.empty()){
		f = fat(s.size()-1);
		i = (int)(k/f);
		k = k%f;
		p.append(1, s[i]);
		s.erase(s.begin()+i);
	}
	return p;
}

int main(){
	int T, tam;
	ull N;
	char s[MAX];
	string ans;
	precalc();
	scanf("%d\n", &T);
	while(T--){
		scanf("%s\n", s);
		scanf("%llu\n", &N);
		tam = strlen(s);
		sort(s, s+tam);
		ans = permute(s, N % fat(tam));
		printf("%s\n", ans.c_str());
	}
	return 0;
}
