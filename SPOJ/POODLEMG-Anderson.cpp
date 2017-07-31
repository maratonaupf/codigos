/*
 * Anderson A. Fontana
 * spoj POODLEMG - Poodle
 */

#include <iostream>

using namespace std;

int main()
{
	int N, P, pag;
	while (cin >> N >> P && N!=0 && P!=0)
	{
		pag = N/P;
		if (N%P!=0)
			pag++;

		cout << "P";
		if (pag < 6)
			cout << "oo";
		else if (pag > 20)
			cout << "oooooooooooooooo";
		else
		{
			pag -= 4;
			while (pag--)
				cout << "o";
		}
		cout << "dle" << endl;
	}
	return 0;
}