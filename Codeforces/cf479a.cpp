/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/479/A
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int getMaxValue(int a, int b, int c){
    int ans = 0;
    ans = max(a+b+c, ans);
    ans = max(a+b*c, ans);
    ans = max(a*b+c, ans);
    ans = max(a*b*c, ans);
    ans = max((a+b)*c, ans);
    ans = max(a*(b+c), ans);
    return ans;
}

int main(){
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c) != EOF){
        printf("%d\n", getMaxValue(a, b, c));
    }
    return 0;
}
