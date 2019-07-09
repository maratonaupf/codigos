#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<int> vi;

int main(){
    int n, i, tot, l, ans;
    while(scanf("%d", &n) != EOF){
        vi v(n, 0);
        for(i = 0; i < n; i++){
            scanf("%d", &v[i]);
            if(i > 0){
                v[i] += v[i-1];
            }
        }
        tot = v.back();
        l = tot / 3;
        ans = 0;
        for(i = 0; v[i] <= l; i++){
            if(binary_search(v.begin(), v.end(), v[i])
            && binary_search(v.begin(), v.end(), v[i] + l)
            && binary_search(v.begin(), v.end(), v[i] + l*2)){
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

