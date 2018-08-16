/*
 * Leonardo Deliyannis Constantin
 * URI 2846 - Fibonot
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int fibonot(int n){
    int a = 0, b = 1, cnt = 0, ans = 4;
    while(cnt < n){
        for(int i = a+1; i < b; i++){
            ans = i;
            if(++cnt == n)
                break;
        }
        swap(a, b);
        b = a+b;
    }
    return ans;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%d\n", fibonot(n));
    }
    return 0;
}
