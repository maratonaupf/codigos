/*
 * Leonardo Deliyannis Constantin
 * URI 2417 - Campeonato
*/

#include <stdio.h>

int main(){
    int cv, ce, cs, fv, fe, fs;
    while(scanf("%d %d %d %d %d %d", &cv, &ce, &cs, &fv, &fe, &fs) != EOF){
        int cp = cv*3 + ce, fp = fv*3 + fe;
        if(cp > fp || (cp == fp && cs > fs))
            printf("C\n");
        else if(cp < fp || (cp == fp && cs < fs))
            printf("F\n");
        else
            printf("=\n");
    }
    return 0;
}
