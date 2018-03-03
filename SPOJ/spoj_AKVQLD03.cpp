/*
 * Leonardo Deliyannis Constantin
 * http://www.spoj.com/problems/AKVQLD03/
*/

#include <stdio.h>
#include <vector>
using namespace std;

typedef vector<int> vi;
#define LSOne(S) (S & (-S))

class FenwickTree{
private:
	vi ft;
public:
	FenwickTree(){}
	FenwickTree(int n) { ft.assign(n+1, 0); }
	int rsq(int b){
		int sum = 0; for(; b; b -= LSOne(b)) sum += ft[b];
		return sum;
	}
	int rsq(int a, int b){
		return rsq(b) - (a == 1 ? 0 : rsq(a-1));
	}
	void adjust(int k, int v){
		for(; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
	}
};

int main(){
	int N, Q, a, b;
	char op[8];
	while(scanf("%d %d", &N, &Q) != EOF){
		FenwickTree ft(N);
		while(Q--){
			scanf("%s %d %d", op, &a, &b);
			if(op[0] == 'a'){
				ft.adjust(a, b);
			}else{
				printf("%d\n", ft.rsq(a, b));
			}
		}
	}
	return 0;
}
