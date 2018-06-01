// Leonardo Deliyannis Constantin
// http://codeforces.com/problemset/problem/282/A

#include <stdio.h>

int main(){
    int N, x;
    char op[5];
    while(scanf("%d", &N) != EOF){
        x = 0;
        while(N--){
            scanf("%s", op);
            x += (op[1] == '+') ? 1 : -1;
        }
        printf("%d\n", x);
    }
    return 0;
}
