/*
 * Anderson A. Fontana
 * Uva 11459 - Snakes and Ladders
 */

#include <iostream>
#include <string.h>
#include <map>

using namespace std;

int main()
{
	int cases, a,b,c, i, x,y, p;
	bool fim;
	cin >> cases;
	while (cases--)
	{
		cin >> a >> b >> c;
		map<int, int> bypass;
		int players[a];
		for (i = 0; i < a; ++i) players[i] = 1;		// Jogadores iniciam na posição 1
		for (i = 0; i < b; ++i)
		{
			cin	>> x >> y;
			bypass[x] = y;
		}
		p=0;
		fim = false;
		for (i = 0; i < c; ++i)
		{
			cin >> x;
			if (!fim)
			{
				x += players[p];
				if (bypass.find(x) != bypass.end())
					x = bypass[x];
				if (x >= 100)
				{
					fim = true;
					x=100;
				}
				players[p] = x;
				p=(p+1)%a;							// Controle de um vetor circular
			}
		}
		for (i = 0; i < a; ++i)
			cout << "Position of player " << i+1 << " is " << players[i] << "." << endl;
	}
	return 0;
}