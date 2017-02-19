/*
 * Anderson A. Fontana
 * Uva 11172 - Relational Operators
 */

#include <iostream>

using namespace std;

int main()
{
	int a,b,n;
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		if (a > b)
			cout << '>' << endl;
		else if (a < b)
			cout << '<' << endl;
		else
			cout << '=' << endl;
	}
	return 0;
}