/*
 * Leonardo Deliyannis Constantin
 * UVa 1103 - Ancient Messages
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cassert>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
#define MAX 212

typedef pair<int, int> ii;

int H, W;
char grid[MAX][MAX];

void pgrid(){
	for(int i= 0; i < H; i++){
		fprintf(stderr, "%s\n", grid[i]);
	}
}

const int di[] = { -1,  0, 0, 1 };
const int dj[] = {  0, -1, 1, 0 };

inline int hexToDec(const int c){
	return isdigit(c) ? (c - '0') : (10 + c - 'a');
}

void hexToBin(char *t, const char *s){
	int j, mask, i;
	for(j = 0; j < W; j++){
		mask = hexToDec(s[j]);
		for(i = 0; i < 4; i++){
			t[j*4 + i] = (mask&(1<<(3-i)) ? 1 : 0) + '0';
		}
	}
	t[W*4] = 0;
}

bool isValid(int i, int j){
	return 0 <= i && i < H && 0 <= j && j < W;
}

int ff(int si, int sj, char c0, char c1){
	int i, j, k, i2, j2, ret = 0;
	if(grid[si][sj] != c0) return -1;
	grid[si][sj] = c1;
	stack<ii> q;
	q.push(ii(si, sj));
	while(!q.empty()){
		i = q.top().first;
		j = q.top().second;
		q.pop();
		for(k = 0; k < 4; k++){
			i2 = i+di[k];
			j2 = j+dj[k];
			if(isValid(i2, j2)){ 
				if(grid[i2][j2] == c0){
					grid[i2][j2] = c1;
					q.push(ii(i2, j2));
				}
				else if(c1 == '#' && grid[i2][j2] == '0'){
					ff(i2, j2, '0', '*');
					ret++;
				}
			}
		}
	}
	return ret;
}

int main(){
	int i, j, tc = 0;
	char s[MAX];
	const char g[] = "WAKJSD";
	while(scanf("%d %d\n", &H, &W), H != 0){
		//fprintf(stderr, "Case %d:\n", tc+1);
		for(i = 0; i < H; i++){
			fgets(s, MAX, stdin);
			hexToBin(grid[i], s);
		}
		W *= 4;
		string glyphs = "";
		// floodfill background pixels
		char bg = '.';
		for(i = 0; i < H; i++){
			ff(i, 0, '0', bg);
			ff(0, i, '0', bg);
			ff(i, W-1, '0', bg);
			ff(H-1, i, '0', bg);
		}
		for(i = 0; i < H; i++){
			for(j = 0; j < W; j++){
				if(grid[i][j] == '1'){
					glyphs.push_back(g[ff(i, j, '1', '#')]); }}}
		sort(glyphs.begin(), glyphs.end());
		printf("Case %d: %s\n", ++tc, glyphs.c_str());
		//pgrid();
	}
	return 0;
}
