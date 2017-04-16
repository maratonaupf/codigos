/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/ELEICOES/
 */

#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

bool mycomp(ii a, ii b){
	return a.second < b.second;
}

int main(){
	int T, n;
	while(scanf("%d", &T) != EOF){
		map<int, int> m;
		while(T--){
			scanf("%d", &n);
			m[n]++;
		}
		printf("%d\n", max_element(m.begin(), m.end(), mycomp)->first);
	}
	return 0;
}
