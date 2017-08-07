/*
 * Anderson A. Fontana
 * spoj ENCOTEL - Encontre o telefone
 */

#include <iostream>
#include <cctype>

using namespace std;

int char2int(char c)
{
		 if ('A' <= c && c <= 'C') return 2;
	else if ('D' <= c && c <= 'F') return 3;
	else if ('G' <= c && c <= 'I') return 4;
	else if ('J' <= c && c <= 'L') return 5;
	else if ('M' <= c && c <= 'O') return 6;
	else if ('P' <= c && c <= 'S') return 7;
	else if ('T' <= c && c <= 'V') return 8;
	else if ('W' <= c && c <= 'Z') return 9;
	return 0;
}

int main()
{
	string s;
	while (cin >> s)
	{
		for (char c : s)
			if (isalpha(c))
				cout << char2int(c);
			else
				cout << c;
		cout << endl;
	}
	return 0;
}