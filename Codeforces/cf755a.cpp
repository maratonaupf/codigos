/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/755/A
*/

#include <stdio.h>
#define MAX ((int)1e9)

bool isPrime(int m){
    if(m < 2)
        return false;
    for(int i = 2; i*i <= m; i++)
        if(m % i == 0)
            return false;
    return true;
}

int main(){
    int n, m;
    while(scanf("%d", &n) != EOF){
        for(m = 1; m < MAX; m++)
            if(!isPrime(n*m + 1))
                break;
        printf("%d\n", m);
    }
    return 0;
}
