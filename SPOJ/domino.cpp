/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/DOMINO/
*/

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
// #define DEBP

typedef pair<int, int> ii;

int m[7][8];
bool mark[7][8];
bool used[29];

const int _firstVal[7] = {1, 7, 12, 16, 19, 21, 22};
int pieceCode(int a, int b){
	if(a > b) swap(a, b);
	return _firstVal[a] + b;
}

void readGrid(){
	int i, j;
	for(i = 0; i < 7; i++)
		for(j = 0; j < 8; j++)
			scanf("%d", &m[i][j]);
}

int backtrack(int i, int j){
	int piece, ret = 0;
	if(i >= 7) return 1;
	if(j >= 8) return backtrack(i+1, 0);
	if(mark[i][j]) return backtrack(i, j+1);
	// place piece horizontally
	if(j < 7 && !used[piece = pieceCode(m[i][j], m[i][j+1])] && !mark[i][j+1]){
		used[piece] = mark[i][j] = mark[i][j+1] = true;
		ret += backtrack(i, j+2);
		used[piece] = mark[i][j] = mark[i][j+1] = false;
	}
	// place piece vertically
	if(i < 6 && !used[piece = pieceCode(m[i][j], m[i+1][j])] && !mark[i+1][j]){
		used[piece] = mark[i][j] = mark[i+1][j] = true;
		ret += backtrack(i, j+1);
		used[piece] = mark[i][j] = mark[i+1][j] = false;
	}
	return ret;
}

int main(){
	int T, test;
	scanf("%d", &T);
	for(test = 1; test <= T; test++){
		readGrid();
		memset(mark, 0, sizeof(mark));
		memset(used, 0, sizeof(used));
		printf("Teste %d\n", test);
		printf("%d\n\n", backtrack(0, 0));
	}
	return 0;
}
