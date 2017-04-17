/*
 * Anderson A. Fontana
 * Uri 1260 - Espécies de Madeira
 */

#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int n, c;
	double x;
	string s;
	map<string, int> m;
	cin >> n;
	cin.ignore();
	cin.ignore();
	while (n--)
	{
		c = 0;
		while (true)
		{
			getline(cin, s);
			if (s=="")
				break;
			if (m.find(s) != m.end())
				m[s]++;
			else
				m[s] = 1;
			c++;
		}
		x = 100.00/c;
		for (auto it=m.begin(); it!=m.end(); ++it)
			cout << it->first << ' ' << fixed << setprecision(4) << it->second*x << endl;
		if (n!=0)
			cout << endl;
		m.clear();
	}

	return 0;
}
