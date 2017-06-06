/*
 * Anderson A. Fontana
 * 1140 - Flores Florescem da França
 */

#include <iostream>

using namespace std;

int main()
{
	bool taut;
	int sz;
	char first;
	string s;
	while (getline(cin, s) && s != "*")
	{
		first = tolower(s[0]);
		sz = s.size();
		taut = true;
		for (int i = 1; i < sz; ++i)
		{
			if (s[i]==' ' && i+1 < sz && tolower(s[i+1]) != first)
			{
				taut = false;
				break;
			}
		}
		if (taut)
			cout << "Y" << endl;
		else
			cout << "N" << endl;

	}
	return 0;
}