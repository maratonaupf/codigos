/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/IMPEDIDO/
 */

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int A, D, i;
	while(scanf("%d %d", &A, &D), A != 0){
		vector<int> b(A);
		vector<int> c(D);
		for(i = 0; i < A; i++){
			scanf("%d", &b[i]);
		}
		for(i = 0; i < D; i++){
			scanf("%d", &c[i]);
		}
		sort(b.begin(), b.end());
		sort(c.begin(), c.end());
		printf("%c\n", (b[0] < c[1]) ? 'Y' : 'N');
	}
	return 0;
}