/*
 * Leonardo Deliyannis Constantin
 * URI 1250 - KiloMan
*/

#include <stdio.h>
#define MAX 52

int main(){
    int N, T, i;
    int h[MAX];
	char s[MAX];
    int shots;
    scanf("%d", &N);
    while(N--){
        scanf("%d", &T);
        for(i = 0; i < T; i++){
            scanf("%d", h+i);
        }
        scanf("%s", s);
        shots = 0;
        for(i = 0; i < T; i++){
            shots += (h[i] > 2 && s[i] == 'J') || (h[i] <= 2 && s[i] == 'S');
        }
        printf("%d\n", shots);
    }
	return 0;
}
