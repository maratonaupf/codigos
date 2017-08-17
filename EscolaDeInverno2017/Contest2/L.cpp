/*
 * Leonardo Deliyannis Constantin, 
 * Luis Fernando Fontoura Spaniol
 * L - Competição de chocolate
 */

#include <stdio.h>

int main(){
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF){
		printf("%s\n", n % (m+1) != 0 ? "Paula" : "Carlos");
	}
	return 0;
}
