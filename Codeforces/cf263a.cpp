/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/263/A
*/

#include <stdio.h>
#include <stdlib.h>

int manhattan(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

int main(){
    int i, j, n, x, y;
    while(1){
        x = y = 0;
        for(i = 0; i < 5; i++)
            for(j = 0; j < 5; j++){
                if(scanf("%d", &n) == EOF)
                    return 0;
                if(n == 1)
                    x = i, y = j;
            }
        printf("%d\n", manhattan(x, y, 2, 2));
    }
    return 0;
}
