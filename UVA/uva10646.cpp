#include<stdio.h>
#include<vector>
#include<cassert>
using namespace std;

struct card{
	char rank, suit;
	card(char *s){
		rank = s[0]; 
		suit = s[1];
	}
};

int valueOf(card c){
	return ('2' <= c.rank && c.rank <= '9') ? c.rank - '0' : 10;
}

int main(void){
	int T, tc, i;
	int X, Y;
	char s[4];
	vector<card> pile;
	vector<card> hand;
	scanf("%d\n", &T);
	for(tc = 1; tc <= T; tc++){
		/* Initially there is a pile consisting 
		 * of 52 cards with card faces down. */
		for(i = 0; i < 52; i++){
			
			scanf("%s ", s);
			pile.push_back(card(s));
		}
		/*  Take the top 25 cards of the pile in the hand. */
		hand.assign(pile.begin() + 27, pile.begin() + 52);
		pile.erase(pile.begin() + 27, pile.begin() + 52);
		assert((int)hand.size() == 25);
		assert((int)pile.size() == 27);
		Y = 0;
		for(i = 0; i < 3; i++){
			X = valueOf(pile.back());
			Y += X;
			pile.pop_back();
			pile.erase(pile.end()-(10-X), pile.end());
		}
		pile.insert(pile.end(), hand.begin(), hand.end());
		printf("Case %d: %c%c\n", tc, pile[Y-1].rank, pile[Y-1].suit);
		pile.clear();
		hand.clear();
	}
	return 0;
}
