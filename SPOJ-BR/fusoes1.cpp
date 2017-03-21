#include<stdio.h>
#include<vector>
using namespace std;

typedef vector<int> vi;

class UnionFind{
private: vi p, rank;
public:
	UnionFind(int N){
		rank.assign(N, 0);
		p.assign(N, 0);
		for(int i = 0; i < N; i++) p[i] = i;
	}
	int findSet(int i){ return (p[i] == i) ? i : p[i] = findSet(p[i]); }
	bool isSameSet(int i, int j){ return findSet(i) == findSet(j); }
	void unionSet(int i, int j){
		if(!isSameSet(i, j)){
			int x = findSet(i), y = findSet(j);
			if(rank[x] > rank[y]) p[y] = x;
			else{
				p[x] = y;
				if(rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};

int main(void){
	int N, K, a, b;
	char op;
	while(scanf("%d %d\n", &N, &K) != EOF){
		UnionFind uf(N);
		while(K--){
			scanf("%c %d %d\n", &op, &a, &b);
			switch(op){
				case 'C':
					printf("%c\n", uf.isSameSet(a, b) ? 'S' : 'N');
					break;
				case 'F':
					uf.unionSet(a, b);
					break;
			}
		}
	}
	return 0;
}
