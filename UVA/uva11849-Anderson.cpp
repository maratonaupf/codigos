/*
 * Anderson A. Fontana
 * Uva 11849 - CD
 */

#include <iostream>
#include <map>

using namespace std;

int main()
{
	int a, b, aux, c;
	map<int, bool> cds;
	while (cin >> a >> b && a!=0 && b!=0)
	{
		while (a--)
		{
			cin >> aux;
			cds[aux] = true;
		}
		c = 0;
		while (b--)
		{
			cin >> aux;
			if (cds.find(aux) != cds.end())
				c++;
		}
		cout << c << endl;
		cds.clear();
	}
	return 0;
}