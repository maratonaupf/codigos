/*
 * Anderson A. Fontana
 * Uva 10813 - Traditional BINGO
 */

#include <iostream>

using namespace std;

struct cell
{
	bool mark;
	int value;
};

bool bingo();

cell card[5][5];

int main()
{
	int n, r, c, i, val, numeros_anunciados;
	bool achou, fim;
	cin >> n;
	while (n--)
	{
		for (r = 0; r < 5; ++r)
			for (c = 0; c < 5; ++c)
				if (r==2 && c==2)
				{
					card[r][c].value = 0;
					card[r][c].mark = true;
				}
				else
				{
					cin >> card[r][c].value;
					card[r][c].mark = false;
				}
		fim = false;
		for (i = 1; i <= 75; ++i)
		{
			cin >> val;
			if (!fim)
			{
				if (0 < val && val <= 15)		c=0;
				else if (15 < val && val <= 30) c=1;
				else if (30 < val && val <= 45) c=2;
				else if (45 < val && val <= 60) c=3;
				else if (60 < val && val <= 75) c=4;
				achou = false;
				for (r = 0; r < 5; ++r)
					if (card[r][c].value == val)
					{
						achou = true;
						break;
					}
				if (achou)
				{
					card[r][c].mark = true;
					fim = bingo();
					if (fim)
						numeros_anunciados = i;
				}	
			}
		}
		cout << "BINGO after " << numeros_anunciados << " numbers announced" << endl;
	}
	return 0;
}

bool bingo()
{
	int r, c;
	bool ok;

//		'-.
	ok = true;
	for (r = 0; r < 5; ++r)
		if (!card[r][r].mark){ ok = false; break; }
	if (ok) return true;

//		.-'
	ok = true;
	for (r = 0; r < 5; ++r)
		if (!card[r][4-r].mark){ ok = false; break; }
	if (ok) return true;

//		---
	for (r = 0; r < 5; ++r)
	{
		ok = true;
		for (c = 0; c < 5; ++c)
			if (!card[r][c].mark){ ok = false; break; }
		if (ok) return true;
	}

//		 |
	for (c = 0; c < 5; ++c)
	{
		ok = true;
		for (r = 0; r < 5; ++r)
			if (!card[r][c].mark){ ok = false; break; }
		if (ok) return true;
	}

	return false;
}