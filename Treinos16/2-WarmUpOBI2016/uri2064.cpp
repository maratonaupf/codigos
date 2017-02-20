#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define MAX 112345
//#define DEBP // DEBug Print

int k, m, n;
char dog[MAX];

bool isFav[26];
int quant[26];
char swaps[26];
char bestSwaps[26];

void getFavLetters(){
	getchar();
	memset(isFav, 0, sizeof(isFav));
	for(int i = 0; i < k; i++){
		isFav[getchar() - 'a'] = true;
	}
}

void getDogName(){
	getchar();
	memset(quant, 0, sizeof(quant));
	for(int i = 0; i < m; i++){
		quant[(dog[i] = getchar()) - 'a']++;
	}
	dog[m] = '\0';
}

void setSwaps(){
	for(int i = 0; i < 26; i++){
		bestSwaps[i] = swaps[i] = i + 'a';
	}
}

int countFav(){
	int favs = 0;
	for(int i = 0; i < 26; i++){
		if(isFav[i]) favs += quant[i];
	}
	return favs;
}

void updateSwaps(int a, int b){
	int pa, pb;
	for(int i = 0; i < 26; i++){
		if(swaps[i] == a) pa = i;
		if(swaps[i] == b) pb = i;
	}
	swap(swaps[pa], swaps[pb]);
	swap(quant[a - 'a'], quant[b - 'a']);
}

void executeSwaps(){
	for(int i = 0; i < m; i++){
		dog[i] = bestSwaps[dog[i] - 'a'];
	}
}

int main(void){
	int maxfav, aux;
	char a, b;
	while(scanf("%d %d %d", &k, &m, &n) != EOF){
		getFavLetters();
		getDogName();
		setSwaps();
		maxfav = countFav();
		while(n--){
			scanf(" %c %c", &a, &b);
			updateSwaps(a, b);
			aux = countFav();
			if(maxfav < aux){
				maxfav = aux;
				memcpy(bestSwaps, swaps, 26);
			}
		}
		executeSwaps();
		printf("%d\n%s\n", maxfav, dog);
	}
	return 0;
}
