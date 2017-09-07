/*
 * Leonardo Deliyannis Constantin
 * URI 2547 - Montanha-Russa
*/

#include <stdio.h>

int main(){
	int N, amin, amax, alt, cnt;
	while(scanf(" %d %d %d", &N, &amin, &amax) != EOF){
		cnt = 0;
		while(N--){
			scanf(" %d", &alt);
			if(amin <= alt && alt <= amax)
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
