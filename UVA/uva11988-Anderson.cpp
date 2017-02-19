/*
 * Anderson A. Fontana
 * Uva 11988 - Broken Keyboard (a.k.a. Beiju Text)
 */

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<char> out;
	list<char>::iterator it;
	string in;
	while (getline(cin, in))
	{
		for(char c : in)
		{
			if (c == '[' || c == ']')
			{
				if (out.empty())
					continue;
				if (c == '[')
					it = out.begin();
				else
					it = out.end();
			}
			else
				if (out.empty())
				{
					out.push_back(c);
					it = out.end();
				}
				else
					out.insert(it, c);

		}
		for (auto i : out)
			cout << i;
		cout << endl;
		out.clear();
	}
	return 0;
}