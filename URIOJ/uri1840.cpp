// URI 1840 - O Prisioneiro de Azkaban
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define INFTO 1123456789
//#define DEBP // DEBug Print

typedef char card[4];
typedef char player[12];

int suitOf(char a){
	return a =='D' ? 0 : a =='S' ? 1 : a =='H' ? 2 : a =='C' ? 3 : -1;
}

int compareSuits(char a, char b){
	int tmpA = suitOf(a);
	int tmpB = suitOf(b);
	return tmpA < tmpB ? -1 : tmpA == tmpB ? 0 : 1;
}

int rankOf(char a){
	return '4' <= a && a <= '7' ? a-'0' : a == 'Q'? 8 : a=='J' ? 9 : a=='K'? 10 : a=='A' ? 11 : a=='2' || a =='3' ? 10+a-'0': -1;
}

int compareRanks(char a, char b){
	int tmpA = rankOf(a);
	int tmpB = rankOf(b);
	return tmpA < tmpB ? -1 : tmpA == tmpB ? 0 : 1;
}

int trump;
int isTrump(char a){
	return trump == rankOf('3') ? a == '4': (rankOf(a) - trump) == 1;
}

int compareCards(card a, card b){
	if(isTrump(a[0]) && isTrump(b[0])){
		return compareSuits(a[1], b[1]);
	}
	return isTrump(b[0]) ? -1 : isTrump(a[0]) ? 1 : compareRanks(a[0], b[0]);
}

int main(void){
	int N;
	card onTable;
	card onGame[4];
	player name[4];
	int bet[4];
	int roundsMade[4];
	int score[4];
	int i, biggest, tie, winner;
	while(scanf("%d %s", &N, onTable) != EOF){
		trump = rankOf(onTable[0]);
		getchar();
		
		for(i = 0; i < 4; i++){
			scanf("%s %d", name[i], bet+i);
			roundsMade[i] = 0;
			score[i] = INFTO;
		}
		
		while(N--){
			getchar();
			
			// read cards and find biggest
			biggest = 0;
			for(i = 0; i < 4; i++){
				scanf("%s", onGame[i]);
				if(i > 0 && compareCards(onGame[biggest], onGame[i]) == -1){
					biggest = i;
				}
			}
			
			// search for a tie
			tie = -1;
			for(i = 0; i < 4; i++){
				if(compareCards(onGame[biggest], onGame[i]) == 0){
					if(++tie) break;
				}
			}
			
			if(tie == 0){
				roundsMade[biggest]++;
			}
		}
		
		winner = 0;
		for(i = 0; i < 4; i++){
			score[i] = abs(bet[i] - roundsMade[i]);
			if(score[winner] > score[i]){
				winner = i;
			}
		}
		
		tie = -1;
		for(i = 0; i < 4; i++){
			if(score[i] == score[winner]){
				if(++tie) break;
			}
		}
		
		printf("%s\n", tie ? "*" : name[winner]);
#ifdef DEBP
		for(i = 0; i < 4; i++){
			printf("%s: %d rounds made - score: %d\n", name[i], roundsMade[i], score[i]);
		}
#endif
	}
	return 0;
}