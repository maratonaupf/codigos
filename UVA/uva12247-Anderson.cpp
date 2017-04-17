/*
 * Anderson A. Fontana
 * Uva 12247 - Jollo
 */

#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;
bitset<53> used;

int prox(int x)
{
	int i;
	for (i = x; i <= 53; ++i)
		if (!used[i])
			break;
	if (i >= 53)
		return -1;
	else
		return i;
}

int main()
{
	int i, princess[3], prince[2];
	while (cin >> princess[0] >> princess[1] >> princess[2] >> prince[0] >> prince[1] && princess[0] != 0)
	{
		sort(princess, princess+3);
		sort(prince, prince+2);
		used.reset();
		for (i = 0; i < 3; ++i) used[princess[i]] = true;
		for (i = 0; i < 2; ++i) used[prince[i]] = true;

		if (prince[0] > princess[2])
			cout << prox(1) << endl;
		else if (prince[1] < princess[1] || (prince[0] < princess[1] && prince[1] < princess[2]))
			cout << "-1" << endl;
		else
			if (prince[1] > princess[2] && prince[0] < princess[1])
				cout << prox(princess[2]) << endl;
			else
				cout << prox(princess[1]) << endl;
	}
	return 0;
}