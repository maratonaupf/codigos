/*
 * Leonardo Deliyannis Constantin
 * URI 2400 - Balé
*/

#include <stdio.h>
#include <vector>
using namespace std;
#define LSOne(S) (S & (-S))
#define MAX 112345

class FenwickTree{
private: 
    vector<int> ft;
public:
    FenwickTree(int N){
        ft.assign(N+1, 0);
    }
    int rsq(int b){
        int sum = 0;
        while(b > 0){
            sum += ft[b];
            b -= LSOne(b);
        }
        return sum;
    }
    int rsq(int a, int b){
        return rsq(b) - ((a == 1) ? 0 : rsq(a - 1));
    }
    void adjust(int k, int v){
        for(; k < (int)ft.size(); k += LSOne(k))
            ft[k] += v;
    }
};

int main(){
    int N, i, b, ans;
    while(scanf("%d", &N) != EOF){
        ans = 0;
        FenwickTree ft(N);
        for(i = 0; i < N; i++){
            scanf("%d", &b);
            ans += i - ft.rsq(b);
            ft.adjust(b, 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
