/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/158/B
*/

#include <stdio.h>
#include <string.h>
#include <cassert>
#include <algorithm>
using namespace std;

int cnt[4];

int combine(int a){
    int tmp;
    if(a == 3){
        tmp = min(cnt[3], cnt[1]);
        cnt[3] -= tmp;
        cnt[1] -= tmp;
        return tmp;
    }
    if(a == 2){
        tmp = min(cnt[2], cnt[1]/2);
        cnt[2] -= tmp;
        cnt[1] -= tmp*2;
        if(cnt[1] == 1 && cnt[2] == 1){
            cnt[2] = cnt[1] = 0;
            tmp++;
        }
        return tmp;
    }
    tmp = cnt[1] / 4;
    cnt[1] -= tmp*4;
    tmp += cnt[1] ? 1 : 0;
    cnt[1] = 0;
    return tmp;
}

int main(){
    int n, s, ans;
    while(scanf("%d", &n) != EOF){
        ans = 0;
        memset(cnt, 0, sizeof(cnt));
        while(n--){
            scanf("%d", &s);
            if(s == 4)
                ans++;
            else if(cnt[4-s] > 0){
                cnt[4-s]--;
                ans++;
            }
            else
                cnt[s]++;
        }
        assert(cnt[2] < 2);
        ans += combine(3);
        ans += combine(2);
        ans += combine(1);
        ans += cnt[2];
        ans += cnt[3];
        cnt[2] = cnt[3] = 0;
        printf("%d\n", ans);
    }
    return 0;
}
