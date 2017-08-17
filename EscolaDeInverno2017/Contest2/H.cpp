/*
 * Leonardo Deliyannis Constantin
 * H - Macaco Rural
 */

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
#define INFTO ((int)2e9 + 1)

typedef long long ll;
typedef vector<ll> vll;

int main(){
	int N, i;
	vll v;
	while(scanf("%d", &N), N != 0){
		v.assign(N, 0);
		for(i = 0; i < N; i++){
			scanf("%lld", &v[i]);
		}
		sort(v.begin(), v.end());
		for(i = 0; i < N/2; i++){
			v[i] += v[N-1-i];
			v.pop_back();
		}
		printf("%lld\n", *max_element(v.begin(), v.end()));
		v.clear();
	}
	return 0;
}
