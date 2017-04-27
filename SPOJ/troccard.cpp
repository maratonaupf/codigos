/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/TROCCARD/
 */

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX (1e5 + 1)

int main(){
	int A, B, card;
	int emA, emB;
	while(scanf("%d %d", &A, &B), A != 0){
		vector<bool> va(MAX, false), vb(MAX, false);
		while(A--){
			scanf("%d", &card);
			va[card] = true;
		}
		while(B--){
			scanf("%d", &card);
			vb[card] = true;
		}
		emA = emB = 0;
		for(int i = 0; i < MAX; i++){
			if(va[i] && !vb[i]) emA++;
			if(vb[i] && !va[i]) emB++;
		}
		printf("%d\n", min(emA, emB));
	}
	return 0;
}
