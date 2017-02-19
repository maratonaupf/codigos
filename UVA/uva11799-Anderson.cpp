/*
 * Anderson A. Fontana
 * Uva 11799 - Horror Dash
 */

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	int n, i, maior, atual;
	string s;
	cin >> n;
	cin.ignore();
	for (i = 1; i <= n; ++i)
	{
		getline(cin, s);
		stringstream ss{s};
		maior = -1;
		while (ss >> atual)
			if (maior < atual)
				maior = atual;
		cout << "Case " << i << ": " << maior << endl;
	}
	return 0;
}