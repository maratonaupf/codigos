/*
 * Anderson A. Fontana
 * Uva 10038 - Jolly Jumpers
 */

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int i, n, prev, now, absolute;
	bool jolly;
	while (cin >> n)
	{
		bool ok[n];
		for (i = 0; i < n; ++i)
			ok[i] = false;

		jolly = true;
		cin >> prev;
		for (i = 1; i < n; ++i)
		{
			cin >> now;
			absolute = abs(prev-now);
			if (absolute < n)
				ok[absolute] = true;
			else
				jolly = false;
			prev = now;
		}

		for (i = 1; i < n; ++i)
			if (!ok[i])
			{
				jolly = false;
				break;
			}

		if (jolly || n==1)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
	}
	return 0;
}