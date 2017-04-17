/*
 * Anderson A. Fontana
 * Uri 1471 - Mergulho
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	int i, N, R;
	bool allive; // all + alive :P
	while (cin >> N >> R)
	{
		for (i = 1; i <= N; ++i)
			v.push_back(i);

		while (R--)
		{
			cin >> i;
			v[i-1] = 0;
		}

		allive = true;
		for (i = 0; i < N; ++i)
			if (v[i] != 0)
			{
				cout << v[i] << " ";
				allive = false;
			}

		if (allive)
			cout << "*";
		cout << endl;
		v.clear();
	}
	return 0;
}