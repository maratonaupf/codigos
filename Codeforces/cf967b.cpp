/*
 * Leonardo Deliyannis Constantin
 * CodeForces 967 B - Watering System
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 112345

int n, A, B, S;
int s[MAX];

int main(){
    int i, ans;
    while(scanf("%d %d %d", &n, &A, &B) != EOF){
        S = 0;
        for(i = 0; i < n; i++){
            scanf("%d", s+i);
            S += s[i];
        }
        sort(s+1, s+n);
        i = n-1;
        while(s[0]*A / S < B){
            S -= s[i];
            i--;
        }
        ans = n-1 - i;
        printf("%d\n", ans);
    }
    return 0;
}
