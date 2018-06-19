/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/988/problem/A
*/ 

#include <stdio.h>
#include <set>
#include <vector>
using namespace std;
#define MAX 112

int main(){
    int N, K, a, i;
    while(scanf("%d %d", &N, &K) != EOF){
        set<int> myset;
        vector<int> v;
        for(i = 1; i <= N; i++){
            scanf("%d", &a);
            if(!myset.count(a)){
                myset.insert(a);
                v.push_back(i);
            }
        }
        if((int)v.size() < K)
            printf("NO\n");
        else{
            printf("YES\n");
            for(i = 0; i < K; i++)
                printf("%d ", v[i]);
            printf("\n");
        }
    }
    return 0;
}
