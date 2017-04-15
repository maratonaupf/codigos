/*
 * Leonardo Deliyannis Constantin
 * http://www.spoj.com/problems/SUMFOUR/
 */

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vi::iterator vi_it;

int main(){
	int N, i, j;
	while(scanf("%d", &N) != EOF){
		vector<int> a(N), b(N), c(N), d(N);
		vector<int> ab, cd;
		for(i = 0; i < N; i++){
			scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
		}
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				ab.push_back(a[i] + b[j]);
				cd.push_back(c[i] + d[j]);
			}
		}
		sort(ab.begin(), ab.end());
		sort(cd.begin(), cd.end());
		int sum = 0, tam = (int)ab.size();
		for(i = 0; i < tam; i++){
			pair<vi_it, vi_it> it = equal_range(cd.begin(), cd.end(), -ab[i]);
			sum += it.second - it.first;
		}
		printf("%d\n", sum);
	}
	return 0;
}
