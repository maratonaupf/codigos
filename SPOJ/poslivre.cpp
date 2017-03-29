/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/POSLIVRE/
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 512
bool ocup[MAX][MAX];

int main(){
	int W, H, N;
	int x1, y1, x2, y2;
	int i, j;
	int pos;
	while(scanf("%d %d %d", &W, &H, &N), W != 0){
		memset(ocup, 0, sizeof(ocup));
		while(N--){
			scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2);
			if(x1 > x2) swap(x1, x2);
			if(y1 > y2) swap(y1, y2);
			for(i = x1; i <= x2; i++)
				for(j = y1; j <= y2; j++)
					ocup[i][j] = true;
		}
		pos = 0;
		for(i = 1; i <= W; i++){
			for(j = 1; j <= H; j++){
				if(!ocup[i][j]) pos++;
			}
		}
		if(pos <= 1)
			printf("There is %s\n", pos ? "one empty spot." : "no empty spots.");
		else
			printf("There are %d empty spots.\n", pos);
	}
	return 0;
}
