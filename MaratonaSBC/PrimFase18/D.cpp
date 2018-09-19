/* 
 * [UPF] Skynet dos Pampas: Ômega
 * Maratona SBC 2018 - Desvendando Monty Hall
*/

#include <stdio.h>

int main(){
	int N, i, p, ans;
	while(scanf("%d", &N) != EOF){
		ans = 0;
		for(i = 0; i < N; i++){
			scanf("%d", &p);
			if(p != 1) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
