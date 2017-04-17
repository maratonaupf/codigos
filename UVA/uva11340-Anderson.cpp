/*
 * Anderson A. Fontana
 * Uva 11340 - Newspaper
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int main()
{
	int n, k, m, value;
	char c;
	double sum;
	string line;
	map<char, int> values;

	cin >> n;
	while (n--)
	{
		cin >> k;
		while (k--)
		{
			cin >> c >> value;
			values[c] = value;
		}
		sum = 0.0;
		cin >> m;
		cin.ignore();
		while (m--)
		{
			getline(cin, line);
			for( char c : line )
				if (values.find(c) != values.end())
					sum += values[c];
		}
		cout << fixed << setprecision(2) << sum/100.0 << "$" << endl;
		values.clear();
	}
	return 0;
}