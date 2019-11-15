/*
 * Leonardo Deliyannis Constantin
 * URI 2868 - Errrou!
*/

#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;

int main(){
    int c;
    int a, b, x, xx, dif;
    char op;
    scanf("%d", &c);
    while(c--){
        scanf("%d %c %d %*c %d", &a, &op, &b, &x);
        xx = (op == '+') ? a + b : (op == '-') ? a - b : a * b;
        dif = abs(xx - x);
        string rseq(dif, 'r');
        string ans = "E" + rseq + "ou!";
        printf("%s\n", ans.c_str());
    }
    return 0;
}
