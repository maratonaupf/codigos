#include<stdio.h>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
#define LEN 32

typedef vector<int> vi;

class UnionFind{
	private: vi id, sz;
	unordered_map<string, int> m;
	public:
	int add(string s){
		if(!m.count(s)){
			int i = (int)id.size();
			id.push_back(m[s] = i);
			sz.push_back(1);
		}
		return m[s];
	}
	int findSet(int p){ return (p == id[p]) ? p : (id[p] = findSet(id[p])); }
	bool isSameSet(int p, int q){ return findSet(p) == findSet(q); }
	int unionSet(int p, int q){
		p = findSet(p);
		q = findSet(q);
		if(p == q) return max(sz[p], sz[q]);
		if(sz[p] > sz[q]) swap(p, q);
		id[p] = q;
		return sz[q] += sz[p];
	}
	void clear(){ id.clear(); sz.clear(); m.clear(); }
};

int main(void){
	int T, N, i1, i2;
	char p1[LEN], p2[LEN];
	UnionFind uf;
	scanf("%d\n", &T);
	while(T--){
		scanf("%d\n", &N);
		while(N--){
			scanf("%s %s\n", p1, p2);
			i1 = uf.add((string)p1);
			i2 = uf.add((string)p2);
			printf("%d\n", uf.unionSet(i1, i2));
		}
		uf.clear();
	}
	return 0;
}
