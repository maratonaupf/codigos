/*
 * Leonardo Deliyannis Constantin
 * https://open.kattis.com/problems/cetvrta
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int x[3], y[3], px, py;
    while(scanf("%d %d", &x[0], &y[0]) != EOF){
        for(int i = 1; i < 3; i++){
            scanf("%d %d", &x[i], &y[i]);
        }
        sort(x, x+3);
        sort(y, y+3);
        px = x[0] != x[1] ? x[0] : x[2];
        py = y[0] != y[1] ? y[0] : y[2];
        printf("%d %d\n", px, py);
    }
    return 0;
}
