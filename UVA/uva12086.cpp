/*
 * Leonardo Deliyannis Constantin
 * UVa 12086 - Potentiometers
*/

#include <stdio.h>
#include <vector>
using namespace std;
#define MAX 200345

class FenwickTree{
private:
    vector<int> ft;
public:
    FenwickTree(){}
    FenwickTree(int n){ ft.assign(n+1, 0); }
    int rsq(int b){
        int sum = 0;
        for(; b > 0; b -= (b & -b)) sum += ft[b];
        return sum;
    }
    int rsq(int a, int b){
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }
    void adjust(int k, int v){
        for(; k < (int)ft.size(); k += (k & (-k))) ft[k] += v;
    }
};

int main(){
	int N, i, caseNo = 0;
    int v[MAX], x, y;
    char op[4];
    while(scanf("%d", &N), N != 0){
        FenwickTree bit(N);
        for(i = 1; i <= N; i++){
            scanf("%d", &v[i]);
            bit.adjust(i, v[i]);
        }
        if(caseNo > 0)
            printf("\n");
        printf("Case %d:\n", ++caseNo);
        while(scanf("%s", op), op[0] != 'E'){
            scanf("%d %d", &x, &y);
            if(op[0] == 'M')
                printf("%d\n", bit.rsq(x, y));
            else{
                bit.adjust(x, y - v[x]);
                v[x] = y;
            }
        }
    }
	return 0;
}
