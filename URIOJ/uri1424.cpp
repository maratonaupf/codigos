#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>
#define MAX 1000010

using namespace std;

int main(void){
	int N, M, v;
	unsigned k;
	map<int,vector<int>> oc;
	while(scanf("%d %d", &N, &M) != EOF){
		for(int i = 1; i <= N; i++){
			scanf("%d", &v);
			oc[v].push_back(i);
		}
		while(M--){
			scanf("%u %d", &k, &v);
			printf("%d\n", (oc[v].size() < k) ? 0 : oc[v][k-1]);
		}
		oc.clear();
	}
	return 0;
}
