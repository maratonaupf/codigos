/*
 * Leonardo Deliyannis Constantin
 * http://www.spoj.com/problems/BSEARCH1/
 */

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int N, Q, i, val, ans;
	while(scanf("%d %d", &N, &Q) != EOF){
		vector<int> v(N);
		for(i = 0; i < N; i++){
			scanf("%d", &v[i]);
		}
		while(Q--){
			scanf("%d", &val);
			ans = (int) (lower_bound(v.begin(), v.end(), val) - v.begin());
			if(ans < 0 || N <= ans || v[ans] != val) ans = -1;
			printf("%d\n", ans);
		}
	}
	return 0;
}