#include<stdio.h>
#include<algorithm>
#include<vector>
#define LEN 32
using namespace std;

typedef vector<int> vi;

struct UnionFind{
	vi id, sz;
	void init(int N){
		sz.assign(N, 1);
		id.reserve(N);
		for(int i = 0; i < N; i++){
			id[i] = i;
		}
	}
	int find(int p){
		if(id[p] == p) return p;
		return id[p] = find(id[p]);
	}
	bool isSameSet(int p, int q){ return find(p) == find(q); }
	void unionSet(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return;
		if(sz[p] > sz[q]) swap(p, q);
		id[p] = q;
		sz[q] += sz[p]; 
	}
};

int main(void){
	UnionFind uf;
	int T, N;
	int i, j;
	int yes, no;
	char query[LEN];
	scanf("%d\n\n", &T);
	while(T--){
		scanf("%d\n", &N);
		uf.init(N);
		yes = no = 0;
		while(fgets(query, LEN, stdin) != NULL && query[0] != '\n'){
			sscanf(query, "%*c %d %d", &i, &j);
			if(query[0] == 'c') 
				uf.unionSet(i-1, j-1);
			if(query[0] == 'q') 
				uf.isSameSet(i-1, j-1) ? yes++ : no++;
		}
		printf("%d,%d\n", yes, no);
		if(T) printf("\n");
	}
	return 0;
}
