/*
 * Leonardo Deliyannis Constantin
 * UVa 12639 - Hexagonal Puzzle
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <assert.h>
using namespace std;

int v[7][6], i[7], r[7];

void rotate(int p){
	int aux = v[p][0];
	memmove(v[p], v[p]+1, sizeof(int));
	v[p][5] = aux;
}


bool solve(){
	int p, q, perm;
	do{
		memset(r, 0, sizeof(r));
		perm = 1;
		for(p = 0; p < 6; p++){
			while(v[i[6]][p] != v[i[p]][(p+r[i[p]]+3)%6]){
				r[i[p]]++;
			}
			q = (p+1)%6;
			while(v[i[p]][(p+r[i[p]]+2)%6] != v[i[q]][(q+r[i[q]]+5)%6]){
				r[i[q]]++;
			}
			perm &= (v[i[6]][q] == v[i[q]][(q+r[i[q]]+4)%6]);
		}
		if(perm) return true;
	}while(next_permutation(i, i+7));
	return false;
}

int main(){
	while(scanf("%d", &v[0][0]) != EOF){
		for(int j = 0; j < 7; j++){
			i[j] = j;
			for(int k = 0; k < 6; k++){
				if(j == 0 && k == 0) continue;
				scanf("%d", &v[j][k]);
			}
		}
		printf("%s\n", solve() ? "YES" : "NO");
	}
    return 0;
}
