#include<stdio.h>
#include<vector>
#include<map>
using namespace std;

typedef vector<int> vi;

int main(void){
	int N, M, i, v, k;
	map<int, vi> m;
	while(scanf("%d %d", &N, &M) != EOF){
		for(i = 1; i <= N; i++){
			scanf("%d", &v);
			m[v].push_back(i);
		}
		while(M--){
			scanf("%d %d", &k, &v);
			if(!m.count(v) || (int)m[v].size() < k) printf("0\n");
			else printf("%d\n", m[v][k-1]);
		}
		m.clear();
	}
	return 0;
}
