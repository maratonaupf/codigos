/*
 * Anderson A. Fontana
 * spoj PALAVRMG - Palavras Ordenadas
 */

#include <iostream>

using namespace std;

bool isOrdered(string s)
{
	for (size_t i = 0; i < s.length()-1; ++i)
		if (toupper(s[i]) >= toupper(s[i+1]))
			return false;
	return true;
}

int main()
{
	int n;
	string s;
	cin >> n;
	while(n--)
	{
		cin >> s;
		cout << s << ": " << (isOrdered(s) ? "O" : "N") << endl;
	}
	return 0;
}