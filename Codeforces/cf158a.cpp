/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/158/A
*/ 

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 51

bool cmp(const int &a, const int &b){
    return a > b;
}

int main(){
    int N, K, v[MAX], i;
    while(scanf("%d %d", &N, &K) != EOF){
        for(i = 0; i < N; i++)
            scanf("%d", v+i);
        sort(v, v+N, cmp);
        if(v[K-1] == 0)
            while(v[K-1] == 0 && K > 0)
                K--;
        else
            while(K < N && v[K-1] == v[K])
                K++;
        printf("%d\n", K);
    }
    return 0;
}
