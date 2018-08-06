/*
 * Leonardo Deliyannis Constantin
 * URI 2410 - Frequência na Aula
*/

#include <stdio.h>
#include <bitset>
using namespace std;
#define MAX 1123456

int main(){
    int N, reg, ans;
    bitset<MAX> bs;
    while(scanf("%d", &N) != EOF){
        bs.reset();
        ans = 0;
        while(N--){
            scanf("%d", &reg);
            if(!bs[reg]){
                bs[reg] = 1;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
