/*
 * Anderson A. Fontana
 * Uri 1533 - Detetive Watson
 */

#include <iostream>

using namespace std;

int main()
{
	int N, x, m, a, im, ia; // (m)aior, (a)ssassino
	while (cin >> N && N!=0)
	{
		for (int i = 1; i <= N; ++i)
		{
			cin >> x;
			if (i==1)
			{
				im = 1;
				ia = 0;
				m = x;
				a = -99999;
			}
			else if (m < x)
			{
				swap(m,a);
				swap(im,ia);
				m = x;
				im = i;
			}
			else if (a < x)
			{
				a = x;
				ia = i;
			}
		}
		// cout << im << "=" << m << " | "<< ia << "=" << a << endl;
		cout << ia << endl;
	}
	return 0;
}