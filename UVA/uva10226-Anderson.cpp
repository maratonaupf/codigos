/*
 * Anderson A. Fontana
 * Uva 10226 - Hardwood Species
 */

#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main()
{
	map<string, int> species;
	int n, sum{0};
	string s;
	cin >> n;
	cin.ignore();
	cin.ignore();
	while (n--)
	{
		while (getline(cin, s) && s != "" && ++sum)
			if (species.find(s) != species.end())
				species[s]++;
			else
				species[s]=1;

		for (auto it = species.begin(); it != species.end(); ++it)
			cout << it->first << " " << fixed << setprecision(4) << it->second*100.00/sum << endl;
		
		if (n > 0)
			cout << endl;
		species.clear();
		sum = 0;
	}
	return 0;
}
