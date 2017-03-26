/*
 * Leonardo Deliyannis Constantin
 * http://poj.org/problem?id=2388
 */

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	int N;
	while(scanf("%d", &N) != EOF){
		vector<int> v(N);
		for(int i = 0; i < N; i++){
			scanf("%d", &v[i]);
		}
		sort(v.begin(), v.end());
		printf("%d\n", v[N/2]);
	} 
	return 0;
}
