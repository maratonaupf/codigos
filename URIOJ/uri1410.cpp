/*
 * Leonardo Deliyannis Constantin
 * URI 1410 - Ele Está Impedido!
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 12

int main(){
    int A, D, i;
    int a[MAX], d[MAX];
    while(scanf("%d %d", &A, &D), A){
        for(i = 0; i < A; i++)
            scanf("%d", a+i);
        for(i = 0; i < D; i++)
            scanf("%d", d+i);
        sort(a, a+A);
        sort(d, d+D);
        printf("%c\n", a[0] < d[1] ? 'Y' : 'N');
    }
    return 0;
}
