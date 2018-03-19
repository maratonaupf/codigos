/*
 * Leonardo Deliyannis Constantin
 * http://www.spoj.com/problems/UPDATEIT/
*/

#include <stdio.h>
#include <vector>
using namespace std;
#define LSOne(S) (S & (-S))

class FenwickTree{
private:
    
public:
    vector<int> ft;
    FenwickTree(){}
    FenwickTree(int N){ ft.assign(N+1, 0); }
    void adjust(int k, int v){
        for(; k <= (int)ft.size(); k += LSOne(k))
            ft[k] += v;
    }
    int rsq(int b){
        int sum = 0;
        for(; b > 0; b -= LSOne(b))
            sum += ft[b];
        return sum;
    }
    int rsq(int a, int b){
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }
};

int main(){
	int T, n, u;
    int l, r, v;
    int q, i;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &n, &u);
        FenwickTree bit(n);
        while(u--){
            scanf("%d %d %d", &l, &r, &v);
            l++, r++;
            bit.adjust(l, v);
            bit.adjust(r+1, -v);
        }
        scanf("%d", &q);
        while(q--){
            scanf("%d", &i);
            printf("%d\n", bit.rsq(i+1));
        }
    }
	return 0;
}
