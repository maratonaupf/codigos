/*
 * Leonardo Deliyannis Constantin
 * UVa 11831 - Sticker Collector Robots
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#define MAX 112
#define LEN 51234

const char dir[] = "NLSO";
const int di[] = { -1,  0, +1,  0 };
const int dj[] = {  0, +1,  0, -1 };

class robot{
private:
	int stickers;
	int face;
	int si, sj;
	int N, M;
	char grid[MAX][MAX];

	bool isOrientation(char c){
		return c == 'N' || c == 'S' || c == 'L' || c == 'O'; 
	}
	bool isValid(int i, int j){
		return 0 <= i && i < N && 0 <= j && j < M;
	}
	bool hasPillar(int i, int j){
		return grid[i][j] == '#';
	}
public:
	void reset(){
		si = sj = -1;
		face = stickers = 0;
	}
	robot(){
		reset();
	}
	bool hasPosition(){
		return si != -1 && sj != -1;
	}
	void setPosition(int i, int j){
		si = i; sj = j;
	}
	
	void setOrientation(char c){
		for(int i = 0; i < 4; i++){
			if(dir[i] == c){
				face = i; break;
			}
		}
	}
	void  turnLeft(){ if(--face == -1) face = 3; }
	void turnRight(){ face = (face + 1) % 4; assert(0 <= face && face < 4); }
	void goAhead(){
		int fi = si + di[face];
		int fj = sj + dj[face];
		if(isValid(fi, fj) && !hasPillar(fi, fj)){
			si = fi; sj = fj;
		}
		if(grid[si][sj] == '*'){
			stickers++;
			grid[si][sj] = '.';
		}
	}
	int getStickers(){
		return stickers;
	}
	void readGrid(int _N, int _M){
		N = _N; M = _M;
		for(int i = 0; i < N; i++){
			fgets(grid[i], MAX, stdin);
			grid[i][M] = 0;
			for(int j = 0; !hasPosition() && j < M; j++){
				if(isOrientation(grid[i][j])){
					setPosition(i, j);
					setOrientation(grid[i][j]);
				}
			}
		}
	}
};

int main(){
	int N, M, S, i;
	char buf[LEN];
	robot Jones;
	while(scanf("%d %d %d\n", &N, &M, &S), N != 0){
		Jones.readGrid(N, M);
		fgets(buf, LEN, stdin);
		for(i = 0; i < S; i++){
			if(buf[i] == 'E') Jones.turnLeft();
			if(buf[i] == 'D') Jones.turnRight();
			if(buf[i] == 'F') Jones.goAhead();
 		}
		printf("%d\n", Jones.getStickers());
		Jones.reset();
	}
	return 0;
}
