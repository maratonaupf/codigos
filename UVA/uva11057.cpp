/*
 * Leonardo Deliyannis Constantin
 * UVa 11057 - Exact Sum
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int T;

ii books(const vi &v, const int M){
	int i, j;
	auto it = upper_bound(v.begin(), v.end(), M/2);
	do{
		it--;
		i = *it;
		j = *lower_bound(v.begin(), v.end(), M - i);
	}while(i+j != M);
	return ii(i, j);
}

int main(){
	int N, M, i;
	vi v;
	ii ans;
	T=1;
	while(scanf("%d", &N) != EOF){
		T+=4;
		v.assign(N, 0);
		for(i = 0; i < N; i++){
			scanf("%d", &v[i]);
		}
		scanf("%d", &M);
		sort(v.begin(), v.end());
		ans = books(v, M);
		printf("Peter should buy books whose prices are %d and %d.\n\n", ans.first, ans.second);
		v.clear();
	}
	return 0;
}
