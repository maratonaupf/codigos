/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/OBIPOKER
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define TAM 5

void countingSort(int c[], int v[]){
	for(int i = 0; i < TAM; i++){
		v[c[i]]++;
	}
}

int score (int c[]){
	int i, v[14], has3, has2a, has2b;
	bool flag1, flag2;
	sort(c, c+TAM);
	// RULE 1
	flag1 = true;
	for(i = 1; i < TAM; i++){
		if(c[i-1] - c[i] != -1) flag1 = false;
	}
	if(flag1) return 200 + c[0];
	// RULE 2
	flag1 = flag2 = true;
	for(i = 2; i < TAM; i++){
		if(c[i-1] != c[i]) flag1 = false;
		if(c[i-2] != c[i-1]) flag2 = false;
	}
	if(flag1 || flag2) return 180 + (c[0] == c[1] ? c[0] : c[1]);
	// RULE 3
	memset(v, 0, sizeof(v));
	countingSort(c, v);
	has3 = has2a = has2b = 0;
	for(i = 1; i <= 13; i++){
		if(v[i] == 3) has3 = i;
		if(v[i] == 2){
			if(!has2a) has2a = i;
			else has2b = i;
		}
	}
	if(has3) return has3 + (has2a ? 160 : 140);
	if(has2a && has2b){
		if(has2a < has2b) swap(has2a, has2b);
		return 3*has2a + 2*has2b + 20;
	}
	if(has2a) return has2a;
	return 0;
}

int main(){
	int N, i, test = 0, c[TAM];
	scanf("%d", &N);
	while(N--){
		for(i = 0; i < TAM; i++){
			scanf("%d", &c[i]);
		}
		printf("Teste %d\n", ++test);
		printf("%d\n\n", score(c));
	}
	return 0;
}
