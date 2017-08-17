/*
 * Leonardo Deliyannis Constantin
 * F - Assalto ao banco central
 */

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
#define INFTO ((int)1e9)
#define setBit(S, j) (S |= (1 << j))

typedef unsigned uns;

inline int contaBits(uns S){
	int cont = 0;
	for(int i = 0; i < 32; i++){
		if(S & (1 << i)) cont++;
	}
	return cont;
}

struct diretor{
	uns keys;
	int dirs;
	diretor(){ 
		keys = 0U;
		dirs = 1;
	}
	diretor(uns _k, int _d){ 
		keys = _k; 
		dirs = _d;
	}
};

void printDirs(const vector<diretor> &v){
	for(int i = 0; i < (int)v.size(); i++){
		printf("i: %d, d: %d, k: %d\n", i, v[i].dirs, contaBits(v[i].keys));
	}
}

int main(){
	int T, M, D, i, C;
	int key, ans;
	uns d, mask;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &M, &D);
		vector<diretor> v(D, diretor());
		for(i = 0; i < D; i++){
			scanf("%d", &C);
			while(C--){
				scanf("%d", &key);
				setBit(v[i].keys, key);
			}
		}
		//printDirs(v);
		ans = INFTO;
		for(d = 0U; d < (uns)(1 << D); d++){
			mask = 0U;
			for(i = 0; i < D; i++){
				if(d & (1 << i)){
					mask |= v[i].keys;
				}
			}
			if(contaBits(mask) >= M){
				ans = min(ans, contaBits(d));
			}
		}
		if(ans == INFTO){
			printf("Desastre!\n"); }
		else{
			printf("%d\n", ans); }
		v.clear();
	}
	return 0;
}
