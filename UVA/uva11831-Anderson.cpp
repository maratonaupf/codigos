/*
 * Anderson A. Fontana
 * Uva 11831 - Sticker Collector Robot
 */

#include <iostream>
#include <vector>

using namespace std;

struct myPair
{
	int x, y;
};

int N, M, S, ortn;		// ortn = orientação
char mat[100][100];
myPair pos;
vector<myPair> mov;


void turn(char cmd)
{
	ortn = (cmd=='D') ? (ortn+5)%4 : (ortn+3)%4;
}

void try2go()
{
	myPair next = {pos.x + mov[ortn].x, pos.y + mov[ortn].y};
	if (0 <= next.x && next.x < N && 0 <= next.y && next.y < M && mat[next.x][next.y] != '#')
		pos = next;
}

int main()
{
	mov.push_back({-1, 0});	// N
	mov.push_back({ 0, 1});	// L
	mov.push_back({ 1, 0});	// S
	mov.push_back({ 0,-1});	// O

	int stickers;
	char cmd;
	while (cin >> N >> M >> S && N!=0 && M!=0 && S!=0)
	{
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				cin >> cmd;
				mat[i][j] = cmd;
				if (cmd=='N' || cmd=='S' || cmd=='L' || cmd=='O')
				{
					switch(cmd)
					{
						case 'N': ortn=0; break;
						case 'L': ortn=1; break;
						case 'S': ortn=2; break;
						case 'O': ortn=3; break;
					}
					pos.x = i;
					pos.y = j;
					mat[i][j] = '.';
				}
			}

		stickers = 0;
		for (int i = 0; i < S; ++i)
		{
			cin >> cmd;
			if (cmd == 'D' || cmd == 'E')
				turn(cmd);
			else
			{
				try2go();
				if (mat[pos.x][pos.y] == '*')
				{
					stickers++;
					mat[pos.x][pos.y] = '.';
				}
			}
		}
		cout << stickers << endl;

	}
	return 0;
}