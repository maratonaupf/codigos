/*
 * Leonardo Deliyannis Constantin
 * URI 2569 - A Bruxa do 7 x 1
*/

#include <stdio.h>

int replaceSevens(int a){
    int ans = a, pot = 1;
    while(a != 0){
        if(a % 10 == 7){
            ans -= 7*pot;
        }
        pot *= 10;
        a /= 10;
    }
    return ans;
}

int main(){
    int a, b, ans;
    char o;
    while(scanf("%d %c %d", &a, &o, &b) != EOF){
        a = replaceSevens(a);
        b = replaceSevens(b);
        ans = (o == '+') ? (a + b) : (a * b);
        printf("%d\n", replaceSevens(ans));
    }
    return 0;
}
