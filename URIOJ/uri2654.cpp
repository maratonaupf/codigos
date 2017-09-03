/*
 * Leonardo Deliyannis Constantin
 * URI 2654 - Godofor
*/

#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 112

struct being{
	string name;
	int p, k, m;
	bool operator >(const being &other) const{
		if(p != other.p) return p > other.p;
		if(k != other.k) return k > other.k;
		if(m != other.m) return m < other.m;
		return name < other.name;
	}
};

bool cmp(const being &a, const being &b){
	return a > b;
}

int main(){
	being v[MAX];
	int N, i;
	char s[MAX];
	while(scanf("%d\n", &N) != EOF){
		for(i = 0; i < N; i++){
			scanf("%s %d %d %d\n", s, &v[i].p, &v[i].k, &v[i].m);
			v[i].name = s;
		}
		sort(v, v+N, cmp);
		printf("%s\n", v[0].name.c_str());
	}
	return 0;
}
