/*
 * Anderson A. Fontana
 * Uva 11906 - Knight in a War Grid
 */

#include <iostream>
#include <vector>

using namespace std;

struct pos
{
	bool visited = false,
		 water = false;
};

struct myPair
{
	int x, y;
};

int R, C, M, N, even, odd;
pos mat[100][100];

bool isValid(int a, int b, int c, int d)
{
	if (0 <= c && c < R && 0 <= d && d < C && !mat[c][d].water)
		return true;
	return false;
}

void insertIfNotRepeated(vector<myPair> &move, int x, int y)
{
	for (size_t i = 0; i < move.size(); ++i)
		if (move[i].x == x && move[i].y == y)
			return;
	move.push_back({x, y});
}

void solveWarGrid()
{
	int a, b, cont;

	vector<myPair> toVisit, move;
	insertIfNotRepeated(move, M, N);
	insertIfNotRepeated(move, M, -N);
	insertIfNotRepeated(move, N, -M);
	insertIfNotRepeated(move, -N, M);
	insertIfNotRepeated(move, -M, N);
	insertIfNotRepeated(move, -M, -N);
	insertIfNotRepeated(move, N, M);
	insertIfNotRepeated(move, -N, -M);

	toVisit.push_back({0,0});
	do
	{
		a = toVisit[0].x;
		b = toVisit[0].y;
		toVisit.erase(toVisit.begin());
		if (!mat[a][b].visited)
		{
			cont = 0;
			for (size_t i = 0; i < move.size(); ++i)
			{
				if (isValid(a, b, a + move[i].x, b + move[i].y))
				{
					cont++;
					toVisit.push_back({a + move[i].x, b + move[i].y});
				}
			}
			mat[a][b].visited = true;
			if (cont%2==0) even++; else odd++;
		}
	} while (!toVisit.empty());
}

int main()
{
	int T, W, x, y;

	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		cin >> R >> C >> M >> N >> W;
		while (W--)
		{
			cin >> x >> y;
			mat[x][y].water = true;
		}
		even = odd = 0;
		solveWarGrid();

		cout << "Case " << i << ": " << even << " " << odd << endl;

		for (int j = 0; j < R; ++j)
			for (int k = 0; k < C; ++k)
				mat[j][k].visited = mat[j][k].water = false;
	}
	return 0;
}