/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/160/A
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 112

int main(){
    int N, i, sum, mySum, cnt;
    int a[MAX];
    while(scanf("%d", &N) != EOF){
        sum = 0;
        for(i = 0; i < N; i++){
            scanf("%d", a+i);
            sum += a[i];
        }
        sort(a, a+N);
        mySum = cnt = 0;
        for(i = N-1; i >= 0; i--){
            mySum += a[i];
            cnt++;
            if(mySum > sum - mySum)
                break;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
