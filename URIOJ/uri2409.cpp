/*
 * Leonardo Deliyannis Constantin
 * URI 2409 - Colchão
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int md[3], dd[2];
    int i;
    while(scanf("%d", md) != EOF){
        for(i = 1; i < 3; i++){
            scanf("%d", md+i);
        }
        for(i = 0; i < 2; i++){
            scanf("%d", dd+i);
        }
        sort(md, md+3);
        sort(dd, dd+2);
        printf("%c\n", (md[1] <= dd[1] && md[0] <= dd[0]) ? 'S' : 'N');
    }
    return 0;
}
