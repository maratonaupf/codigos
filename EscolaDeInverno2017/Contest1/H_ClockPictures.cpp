/*
 * Leonardo Deliyannis Constantin
 * H - Clock Pictures
 */

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
// fine MAX 212345
#define MAX 400005

int b[MAX];
int c1[MAX], c2[MAX];

void kmpPreprocess(int *P, int m){
	int i = 0, j = -1; b[0] = -1;
	while(i < m){
		while(j >= 0 && P[i] != P[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}

bool kmpSearch(int *T, int *P, int n, int m){
	int i = 0, j = 0;
	while(i < n){
		while(j >= 0 && T[i] != P[j]) j = b[j];
		i++; j++;
		if(j == m){
			return true;
			// j = b[j]; // prepare for next match
		}
	}
	return false;
}

void toDifferences(int *v, int sz){
	int aux = v[0];
	for(int i = 0; i < sz-1; i++){
		v[i] = v[i+1] - v[i];
	}
	v[sz-1] = 360000 - (v[sz-1] - aux);
}

void duplicate(int *a, int N){
	for(int i = 0; i < N; i++){
		a[N+i] = a[i];
	}
}

int main(){
	int n, i;
	while(scanf("%d", &n) != EOF){
		for(i = 0; i < n; i++) scanf("%d", &c1[i]);
		for(i = 0; i < n; i++) scanf("%d", &c2[i]);
		sort(c1, c1+n);
		sort(c2, c2+n);
		toDifferences(c1, n);
		toDifferences(c2, n);
		duplicate(c1, n);
		kmpPreprocess(c2, n);
		printf("%s\n", kmpSearch(c1, c2, n*2, n) 
			? "possible" : "impossible");
	}
	return 0;
}
