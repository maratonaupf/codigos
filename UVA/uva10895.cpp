#include<stdio.h>
#include<vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(void){
	int M, N, i, sz, k, j, el;
	vector<vii> m;
	vector<int> r;
	while(scanf("%d %d", &M, &N) != EOF){
		m.assign(N, vii());
		for(i = 0; i < M; i++){
			scanf("%d", &sz);
			for(k = 0; k < sz; k++){
				scanf("%d", &j);
				r.push_back(j-1);
			}
			for(k = 0; k < sz; k++){
				scanf("%d", &el);
				m[r[k]].push_back(ii(i, el));
			}
			r.clear();
		}
		printf("%d %d\n", N, M);
		for(i = 0; i < N; i++){
			sz = (int)m[i].size();
			printf("%d", sz);
			for(k = 0; k < sz; k++){
				printf(" %d", m[i][k].first+1);
			}
			printf("\n");
			for(k = 0; k < sz; k++){
				if(k > 0) printf(" ");
				printf("%d", m[i][k].second);
			}
			printf("\n");
		}
		m.clear();
	}
	return 0;
}
