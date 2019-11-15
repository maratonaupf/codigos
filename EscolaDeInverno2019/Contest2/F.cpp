#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 1123456

typedef long long ll;

int u[MAX], v[MAX];



double bruteForce(int n){
    ll pts = 0, perms = 0;
    for(int i = 0; i < n; i++){
        u[i] = n - i;
        v[i] = i + 1;
    }
    do{
        for(int i = 0; i < n; i++){
            if(u[i] > v[i]){
                pts += u[i];
            }
        }
        perms++;
    }while(next_permutation(v, v+n));
    return (double) pts / (double) perms;
}

double ans[MAX];

void generate(){
    ans[1] = 0.0;
    for(int i = 2; i < MAX; i++){
        double n = (double)i;
        ans[i] = ans[i-1] + (n-1.0)-((n-2.0)/3.0);
    }
}

int main(){
    int n;
    generate();
    while(scanf("%d", &n) != EOF){
        printf("%.10lf\n", ans[n]);
    }
    return 0;
}
