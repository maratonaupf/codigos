/*
 * Leonardo Deliyannis Constantin
 * UVa 118 - Mutant Flatworld Explorers
 */

#include <stdio.h>
#include <string.h>
#define MAX 51
#define LEN 112

int N, M;
int scent[MAX][MAX];
char pos[] = "WNES";
int dx[] = {-1,  0, +1,  0};
int dy[] = { 0, +1,  0, -1};

bool isValid(int x, int y){
	return 0 <= x && x <= N && 0 <= y && y <= M;
}

void execute(int x, int y, const char *c, const char *s){
	bool loss = false;
	int d = strstr(pos, c) - pos;
	int x2, y2;
	for(int p = 0; !loss && s[p]; p++){
		switch(s[p]){
			case 'L': 
				d = (d-1 + 4) % 4; break;
			case 'R':
				d = (d+1) % 4; break;
			case 'F':
				x2 = x+dx[d]; y2 = y+dy[d];
				if(!isValid(x2, y2) && scent[x][y] != 1){
					loss = true;
					scent[x][y] = 1;
				}
				else if(isValid(x2, y2)){
					x = x2; y = y2;
				}
				break;
		}
	}
	printf("%d %d %c%s\n", x, y, pos[d], loss ? " LOST" : "");
}

int main(){
	int x, y;
	char c[3], s[LEN];
	memset(scent, 0, sizeof(scent));
	scanf("%d %d", &N, &M);
	while(scanf("%d %d %s", &x, &y, c) != EOF){
		scanf("%s", s);
		execute(x, y, c, s);
	}
	return 0;
}
