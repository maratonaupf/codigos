#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main(){
    int a, b, c, d;
    int t1, t2;
    while(scanf("%d %d %d %d", &a, &b, &c, &d) != EOF){
        t1 = max(max(a,b), max(c,d)) + min(min(a,b), min(c,d));
        t2 = (a+b+c+d) - t1;
        printf("%d\n", abs(t1-t2));
    }
    return 0;
}
