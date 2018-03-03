/*
 * Leonardo Deliyannis Constantin
 * https://open.kattis.com/problems/bijele
*/

#include <stdio.h>

int v[] = {1, 1, 2, 2, 2, 8};

int main(){
	int i, n;
	while(scanf("%d", &n) != EOF){
		for(i = 0; i < 6; i++){
			if(i > 0) scanf("%d", &n);
			printf("%d%c", v[i]-n, i < 5 ? ' ' : '\n');
		}
	}
	return 0;
}
