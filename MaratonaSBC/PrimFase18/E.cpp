/* 
 * [UPF] Skynet dos Pampas: Ômega
 * Maratona SBC 2018 - Enigma
*/

#include <stdio.h>
#include <string.h>
#define MAX 11234

int main(){
	int i, j;
	char s[MAX], t[MAX];
	while(scanf("%s %s", s, t) != EOF){
		int ans = 0;
		int sz = strlen(t);
		for(i = 0; s[i+sz-1]; i++){
			bool ok = true;
			for(j = 0; ok && t[j]; j++){
				if(t[j] == s[i+j]) ok = false;
			}
			if(ok) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
