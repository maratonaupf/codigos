#include<stdio.h>
#include<string.h>
#include<deque>
#include<cassert>
#define addCard(_p) deck[_p].push_front(toInt(aux[1]))
#define playCard(_p) do{ table.push_front(deck[_p].front()); deck[_p].pop_front(); }while(0)
#define giveCardsTo(_p) while(!table.empty()){ deck[_p].push_back(table.back()); table.pop_back(); }
using namespace std;

int toInt(char c){
	char lookup[] = "23456789TJQKA";
	for(int i = 0; i < 13; i++){
		if(c == lookup[i]) return i+2;
	}
	fprintf(stderr, "INVALID CARD: %c\n", c);
	return -1;
}

int main(void){
	int i, p;
	int cover;
	char aux[4];
	while(scanf("%s", aux), strcmp(aux, "#")){
		deque<int> deck[2], table;
		addCard(0);
		for(i = 1; i < 52; i++){
			scanf("%s", aux);
			addCard(i&1);
		}
		p = cover = 0;
		while(!deck[p].empty()){
			playCard(p);
			if(table.front() > 10){
				p = !p;
				cover = table.front() - 10;
				continue;
			}
			if(cover > 0){
				if(cover == 1){
					cover = 0;
					p = !p;
					giveCardsTo(p);
				}
				else cover--;
			}
			else p = !p;
		}
		printf("%d %2d\n", p+1, (int)deck[!p].size());
	}
	return 0;
}
