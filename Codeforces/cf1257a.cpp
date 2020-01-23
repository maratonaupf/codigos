#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main(){
    int t, n, x, a, b;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d", &n, &x, &a, &b);
        printf("%d\n", min(n-1, abs(a-b) + x));
    }
    return 0;
}
