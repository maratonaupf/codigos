/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/TENTA/
 */

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N, i;
	bool first = true;
	while(scanf("%d", &N), N != 0){
		if(first) first = false;
		else printf("\n");
		vector<int> v(N);
		for(i = 0; i < N; i++){
			scanf("%d", &v[i]);
		}
		sort(v.begin(), v.end());
		do{
			for(i = 0; i < N; ++i){
				printf("%d%c", v[i], i < N-1 ? ' ' : '\n');
			}
		}while(next_permutation(v.begin(), v.end()));
	}
	return 0;
}
