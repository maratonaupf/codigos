/*
 * Leonardo Deliyannis Constantin
 * URI 2456 - Cartas
*/

#include <stdio.h>

int main(){
    int i, v[5];
    bool dec, inc;
    while(scanf("%d", v) != EOF){
        dec = inc = true;
        for(i = 1; i < 5; i++){
            scanf("%d", &v[i]);
            if(v[i-1] < v[i])
                dec = false;
            if(v[i-1] > v[i])
                inc = false;
        }
        printf("%c\n", (dec == inc) ? 'N' : dec ? 'D' : 'C');
    }
    return 0;
}
