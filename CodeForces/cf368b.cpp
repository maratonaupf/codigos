/*
 * Leonardo Deliyannis Constantin
 * CodeForces 368B - Sereja and Suffixes
 */

#include <stdio.h>
#include <set>
using namespace std;
#define MAX 112345

int main(){
	int N, M, i, v[MAX], q;
	int u[MAX];
	while(scanf("%d %d", &N, &M) != EOF){
		for(i = 0; i < N; i++){
			scanf("%d", v+i);
		}
		set<int> st;
		for(i = N-1; i >= 0; i--){
			st.insert(v[i]);
			u[i] = st.size();
		}
		while(M--){
			scanf("%d", &q);
			printf("%d\n", u[q-1]);
		}
	}
	return 0;
}
