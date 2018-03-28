/*
 * Leonardo Deliyannis Constantin
 * URI 2554 - Pizza Antes de BH
*/

#include <stdio.h>
#include <string.h>
#define MAX 13

int main(){
    int N, D, i, p;
    char s[MAX];
    char date[MAX];
    bool allCan, noDateYet;
    while(scanf("%d %d ", &N, &D) != EOF){
        noDateYet = true;
        while(D--){
            scanf("%s", s);
            allCan = true;
            for(i = 0; i < N; i++){
                scanf("%d", &p);
                if(p == 0)
                    allCan = false;
            }
            if(allCan && noDateYet){
                noDateYet = false;
                strcpy(date, s);
            }
        }
        printf("%s\n", noDateYet ? "Pizza antes de FdI" : date);
    }
    return 0;
}
