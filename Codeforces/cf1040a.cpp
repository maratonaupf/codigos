/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/1040/problem/A
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 21
#define INF 0x3f3f3f3f

int n, a, b, v[MAX];

int cost(int i){
    int j = n-1-i;
    if(i > j) return 0;
    if(i == j) return v[i] == 2 ? min(a, b) : 0;
    if(v[i] == 2 && v[j] == 2)
        return cost(i+1) + min(a, b) * 2;
    if(v[i] == 2)
        return cost(i+1) + (v[j] == 0 ? a : b);
    if(v[j] == 2)
        return cost(i+1) + (v[i] == 0 ? a : b);
    if(v[i] == v[j])
        return cost(i+1);
    return INF;
}

int main(){
    while(scanf("%d %d %d", &n, &a, &b) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", v+i);
        }
        int ans = cost(0);
        printf("%d\n", ans < INF ? ans : -1);
    }
    return 0;
}
