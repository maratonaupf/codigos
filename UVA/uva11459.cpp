#include<stdio.h>
#include<string.h>
#define MAX 1123456

int main(void){
	int T, p, s, d, i, roll;
	int pos[MAX], board[100];
	bool nobodyWon;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d", &p, &s, &d);
		memset(pos, 0, sizeof(pos));
		memset(board, 0, sizeof(board));
		while(s--){
			scanf("%d", &i);
			i--;
			scanf("%d", board+i);
			board[i]--;
		}
		i = 0;
		nobodyWon = true;
		while(d--){
			scanf("%d", &roll);
			if(nobodyWon){
				pos[i] += roll;
				if(board[pos[i]] != 0) pos[i] = board[pos[i]];
				if(pos[i] >= 99) nobodyWon = false;
			}
			i = (i+1) % p;
		}
		for(i = 0; i < p; i++){
			printf("Position of player %d is %d.\n", i+1, pos[i]+1);
		}
	}
	return 0;
}
