#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>
using namespace std;
#define TAM 13
#define MSET(arr, val) memset(arr, val, sizeof(arr))

const char suits[] = "SHDC";
map<char, int> suitCount;
map<char, bool> isStopped;

struct card{
	char rank, suit;
	// class constructor
	card(char *s){
		rank = s[0]; 
		suit = s[1];
		suitCount[suit]++;
	}
};

int evaluate(vector<card> &hand, int rule){
	int i, points = 0;
	switch (rule){
		case 1:
			for(i = 0; i < TAM; i++){
				if(hand[i].rank == 'A') points += 4;
				if(hand[i].rank == 'K') points += 3;
				if(hand[i].rank == 'Q') points += 2;
				if(hand[i].rank == 'J') points += 1;
			}
		break;
			
		case 2:
			for(i = 0; i < TAM; i++){
				if(hand[i].rank == 'K' && suitCount[hand[i].suit] == 1)
					points--;
			}
		break;
			
		case 3:
			for(i = 0; i < TAM; i++){
				if(hand[i].rank == 'Q' && suitCount[hand[i].suit] <= 2)
					points--;
			}
		break;
		
		case 4:
			for(i = 0; i < TAM; i++){
				if(hand[i].rank == 'J' && suitCount[hand[i].suit] <= 3)
					points--;
			}
		break;
		
		case 5:
			for(i = 0; i < 4; i++){
				if(suitCount[suits[i]] == 2) points++;
			}
		break;
		
		case 6:
			for(i = 0; i < 4; i++){
				if(suitCount[suits[i]] == 1) points+=2;
			}
		break;
		
		case 7:
			for(i = 0; i < 4; i++){
				if(suitCount[suits[i]] == 0) points+=2;
			}
		break;
	}
	return points;
}

bool checkStoppedSuits(vector<card> &hand){
	int i;
	for(i = 0; i < 4; i++){
		isStopped[suits[i]] = false;
	}
	for(i = 0; i < 13; i++){
		if(hand[i].rank == 'A' ||
		  (hand[i].rank == 'K' && suitCount[hand[i].suit] >= 2) ||
		  (hand[i].rank == 'Q' && suitCount[hand[i].suit] >= 3))
		isStopped[hand[i].suit] = true;
	}
	for(i = 0; i < 4; i++){
		if(!isStopped[suits[i]]) return false;
	}
	return true;
}

int main(void){
	int i, eval[7];
	int totalPoints;
	int noTrump;
	int hasMostCards;
	bool canBidNoTrump;
	char s[4];
	vector<card> hand;
	while(scanf("%s", s) != EOF){
		hand.push_back(card(s));
		for(i = 1; i < 13; i++){
			scanf("%s", s);
			hand.push_back(card(s));
		}
		MSET(eval, 0);
		canBidNoTrump = checkStoppedSuits(hand);
		totalPoints = noTrump = 0;
		for(i = 0; i < 7; i++){
			eval[i] = evaluate(hand, i+1);
			totalPoints += eval[i];
			if(i < 4) noTrump += eval[i]; 
		}
		if(totalPoints < 14)
			puts("PASS");
		else if(canBidNoTrump && noTrump >= 16)
			puts("BID NO-TRUMP");
		else{
			hasMostCards = 0;
			for(i = 0; i < 4; i++){
				if(suitCount[suits[i]] > suitCount[suits[hasMostCards]])
					hasMostCards = i;
			}
			printf("BID %c\n", suits[hasMostCards]);
		}
		hand.clear();
		suitCount.clear();
	}
	return 0;
}
