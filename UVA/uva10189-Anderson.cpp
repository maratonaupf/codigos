/*
 * Anderson A. Fontana
 * Uva 10189 - Minesweeper
 */

#include <iostream>

using namespace std;

int main()
{
	int m,n, i,j, f=1;
	char c;
	cin >> m >> n;
	while (m!=0 && n!=0)
	{
		int cm[m][n];	// CampoMinado
		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j)
			{
				cin >> c;
				if (c == '*')
					cm[i][j] = -1;
				else
					cm[i][j] =  0;
			}

		for (i = 0; i < m; ++i)
			for (j = 0; j < n; ++j)
				if (cm[i][j] == -1)
				{
					if (i-1>=0 && cm[i-1][j]!=-1) cm[i-1][j]++;
					if (j-1>=0 && cm[i][j-1]!=-1) cm[i][j-1]++;
					if (i+1< m && cm[i+1][j]!=-1) cm[i+1][j]++;
					if (j+1< n && cm[i][j+1]!=-1) cm[i][j+1]++;
					if (i-1>=0 && j-1>=0 && cm[i-1][j-1]!=-1) cm[i-1][j-1]++;
					if (i-1>=0 && j+1< n && cm[i-1][j+1]!=-1) cm[i-1][j+1]++;
					if (i+1< m && j-1>=0 && cm[i+1][j-1]!=-1) cm[i+1][j-1]++;
					if (i+1< m && j+1< n && cm[i+1][j+1]!=-1) cm[i+1][j+1]++;
				}

		cout << "Field #" << f++ << ":" << endl;
		for (i = 0; i < m; ++i)
		{
			for (j = 0; j < n; ++j)
				if (cm[i][j] == -1)
					cout << "*";
				else
					cout << cm[i][j];
			cout << endl;
		}

		if (cin >> m >> n && m!=0 && n!=0)
			cout << endl;
		else
			break;
	}
	return 0;
}