/*
 * Anderson A. Fontana
 * spoj TENTA - Brincadeira das Tentativas
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, x;
	vector<int> v;
	while (cin >> n && n != 0)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		do {
			for (int i = 0; i < n; ++i)
				cout << v[i] << " ";
			cout << endl;
		} while (next_permutation(v.begin(), v.end()));
		v.clear();
		cout << endl;
	}
	return 0;
}