/*
 * Leonardo Deliyannis Constantin
 * URI 2708 - Turistas no Parque Huacachina
*/

#include <stdio.h>

int main(){
    char s[11];
    int j, a, t;
    j = a = 0;
    while(scanf("%s", s) != EOF){
        if(s[0] == 'S'){
            scanf("%d", &t);
            j++;
            a += t;
        }
        if(s[0] == 'V'){
            scanf("%d", &t);
            if(j > 0) j--;
            a -= (a > t) ? t : a;
        }
        if(s[0] == 'A'){
            printf("%d\n%d\n", a, j);
            j = a = 0;
        }
    }
    return 0;
}
