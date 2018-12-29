/*
 * Leonardo Deliyannis Constantin
 * URI 2904 - Building a Field
*/

#include <stdio.h>
#include <set>
using namespace std;

int main(){
    int N, i, ac, L, cnt;
    while(scanf("%d", &N) != EOF){
        ac = 0;
        set<int> sums;
        for(i = 0; i < N; i++){
            sums.insert(ac);
            scanf("%d", &L);
            ac += L;
        }
        if(ac&1){
            printf("N\n");
            continue;
        }
        cnt = 0;
        for(int pt : sums){
            if(sums.count(pt + ac/2))
                cnt++;
        }
        printf("%c\n", cnt >= 2 ? 'Y' : 'N');
    }
    return 0;
}
