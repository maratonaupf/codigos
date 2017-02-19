#include<stdio.h>
#include<string.h>

typedef struct _pos{
	int i, j;
} pos;

bool bingo(int card[5][5]){
	int i, j;
	bool row, col, d1, d2;
	// scan every row, column and both diagonals
	d1 = d2 = true;
	for(i = 0; i < 5; i++){
		if(card[i][i] != 0) d1 = false;
		if(card[i][4-i] != 0) d2 = false;
		row = col = true;
		for(j = 0; j < 5; j++){
			if(card[i][j] != 0) row = false;
			if(card[j][i] != 0) col = false;
		}
		if(row || col) break;
	}
	return row || col || d1 || d2;
}

int main(void){
	int N, i, j, card[5][5], num, ans;
	pos v[76];
	scanf("%d", &N);
	while(N--){
		memset(v, -1, sizeof(v));
		for(i = 0; i < 5; i++){
			for(j = 0; j < 5; j++){
				if(i == 2 && j == 2) continue;
				scanf("%d", card[i]+j);
				v[card[i][j]].i = i;
				v[card[i][j]].j = j;
			}
		}
		card[2][2] = 0;
		ans = -1;
		for(i = 1; i <= 75; i++){
			scanf("%d", &num);
			if(v[num].i == -1) continue;
			card[v[num].i][v[num].j] = 0;
			if(ans == -1 && bingo(card)){
				ans = i;
			}
		}
		printf("BINGO after %d numbers announced\n", ans);
	}
	return 0;
}
