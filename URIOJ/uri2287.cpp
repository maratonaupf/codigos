/*
 * Leonardo Deliyannis Constantin
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/2287
 */

#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

bool mycomp(ii a, ii b){
	return a.second < b.second;
}

int main(){
	int N, i, c;
	int teste = 0;
	while(scanf("%d", &N), N != 0){
		vector<map<int, int> > oc(6);
		while(N--){
			map<char, ii> m;
			for(i = 'A'; i <= 'E'; i++){
				int n1, n2;
				scanf("%d %d ", &n1, &n2);
				m[i] = ii(n1, n2);
			}
			for(i = 0; i < 6; i++){
				c = getchar();
				getchar();
				oc[i][m[c].first]++;
				oc[i][m[c].second]++;
			}
		}
		printf("Teste %d\n", ++teste);
		for(i = 0; i < 6; i++){
			printf("%d ", max_element(oc[i].begin(), oc[i].end(), mycomp)->first);
		}
		printf("\n\n");
	}
	return 0;
}
