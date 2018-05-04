/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/976/problem/C
*/

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 312345

struct interval{
    int l, r, idx;    
};

bool cmp(const interval &a, const interval &b){
    if(a.l != b.l)
        return a.l < b.l;
    return a.r > b.r;
}

int main(){
    int N, k, i, j;
    interval a[MAX];
    while(scanf("%d", &N) != EOF){
        for(k = 0; k < N; k++){
            scanf("%d %d", &a[k].l, &a[k].r);
            a[k].idx = k+1;
        }
        sort(a, a+N, cmp);
        i = j = -1;
        for(k = 1; k < N && i == -1; k++){
            if(a[k-1].l <= a[k].l && a[k].r <= a[k-1].r){
                i = a[k].idx;
                j = a[k-1].idx;
            }
        }
        printf("%d %d\n", i, j);
    }
    return 0;
}
