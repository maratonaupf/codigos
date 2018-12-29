/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/contest/1095/problem/B
*/

#include <stdio.h>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f

int getMin(const multiset<int> &st){
    return *(st.begin());
}

int getMax(const multiset<int> &st){
    auto it = st.end();
    it--;
    return *(it);
}

int main(){
    int N, a, lo, ans;
    while(scanf("%d", &N) != EOF){
        multiset<int> st;
        while(N--){
            scanf("%d", &a);
            st.insert(a);
        }
        lo = getMin(st);
        ans = INF;
        st.erase(st.begin());
        ans = min(ans, getMax(st) - getMin(st));
        st.insert(lo);
        st.erase(--(st.end()));
        ans = min(ans, getMax(st) - getMin(st));
        printf("%d\n", ans);
    }
    return 0;
}
