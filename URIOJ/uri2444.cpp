/*
 * Leonardo Deliyannis Constantin
 * URI 2444 - Volume da TV
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int vol, N, x;
    while(scanf("%d %d", &vol, &N) != EOF){
        while(N--){
            scanf("%d", &x);
            vol = (x > 0) ? min(vol+x, 100) : max(vol+x, 0);
        }
        printf("%d\n", vol);
    }
    return 0;
}
