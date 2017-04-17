/*
 * Anderson A. Fontana
 * spoj NUMEROMG - Some dois números
 */

#include <iostream>
#include <math.h>

using namespace std;

int toInt(char c)
{
	if ('0' <= c && c <= '9')
		return (int) c - '0';
	return 10 + (c - 'A');
}

char toChar(int x)
{
	if (0 <= x && x <= 9)
		return x + '0';
	return 'A' + (x-10);
}

int toBase10(string s)
{
	int exp{0}, x{0};
	for (int i = s.length()-1; i >= 0; --i)
		x += toInt(s[i]) * pow(36, exp++);
	return x;
}

string toBase36(int iA)
{
	string str;
	while (iA > 0)
	{
		str.insert(str.begin(), toChar(iA%36));
		iA /= 36;
	}
	return str;
}

int main()
{
	string sA, sB;
	while (cin >> sA >> sB && (sA!="0" || sB!="0"))
		cout << toBase36(toBase10(sA) + toBase10(sB)) << endl;
	return 0;
}