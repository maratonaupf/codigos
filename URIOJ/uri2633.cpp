/*
 * Leonardo Deliyannis Constantin
 * URI 2633 - Churras no Yuri
*/

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAX 11

struct carne{
	char s[22];
	int d;
};

bool cmp(const carne &a, const carne &b){
	return a.d < b.d;
}

carne v[MAX];

int main(){
	int N, i;
	while(scanf("%d\n", &N) != EOF){
		for(i = 0; i < N; i++){
			scanf("%s %d\n", v[i].s, &v[i].d);
		}
		sort(v, v+N, cmp);
		for(i = 0; i < N; i++){
			printf("%s%c", v[i].s, i < N-1 ? ' ' : '\n');
		}
	}
	return 0;
}
