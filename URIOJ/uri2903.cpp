/*
 * Leonardo Deliyannis Constantin
 * URI 2903 - A Symmetrical Pizza
*/

#include <stdio.h>

int solve(int val){
    int cnt = 0, ang = 0;
    while(cnt == 0 || ang != 0){
        ang += val;
        cnt++;
        if(ang >= 36000)
            ang -= 36000;
    }
    return cnt;
}

int main(){
    int a, b, r;
    while(scanf("%d.%d", &a, &b) != EOF){
        r = a*100 + b;
        printf("%d\n", solve(r));
    }
    return 0;
}
