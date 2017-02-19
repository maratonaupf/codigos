/*
 * Anderson A. Fontana
 * Uva 637 - Booklet Printing
 */

#include <iostream>
// #include <cmath>

using namespace std;

int main()
{
	int n, sheets, i, firstPag, lastPag;
	while (cin >> n && n!=0)
	{
		// sheets = ceil( n>2 ? n/4 : n/2 );  // Não funcionou assim
		if(n >= 2)
			if (n%4 == 0)
				sheets = n/4;
			else
				sheets = n/4+1;
		else
			if (n%4 == 0)
				sheets = n/2;
			else
				sheets = n/2+1;
		firstPag = 1;
		lastPag  = ( n>=2 ? sheets*4 : sheets*2 );
		cout << "Printing order for " << n << " pages:" << endl;
		for (i = 1; i <= sheets; ++i)
		{
			cout << "Sheet " << i << ", front: ";
			if (lastPag > n)
				cout << "Blank";
			else
				cout << lastPag;
			cout << ", " << firstPag++ << endl;
			lastPag--;

			if (n >= 2)
			{
				cout << "Sheet " << i << ", back : " << firstPag++ << ", ";
				if (lastPag > n)
					cout << "Blank" << endl;
				else
					cout << lastPag << endl;
				lastPag--;
			}
		}
	}
	return 0;
}