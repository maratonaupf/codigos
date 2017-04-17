/*
 * Anderson A. Fontana
 * Uva 11933 - Splitting Numbers
 */

#include <iostream>
#include <math.h>

using namespace std;

string int2bin(unsigned long long int val)
{
	char c;
	string bin="";
	while(val > 0)
	{
		c = (val & 1) ? '1' : '0';
		val >>= 1;
		bin = c + bin;
	}
	return bin;
}

int main()
{
	unsigned long long int x;
	int a, b, sz, i;
	string bin;
	bool next4a; // next is for A
	while (cin >> x && x!=0)
	{
		a = b = 0;
		bin = int2bin(x);
		sz = bin.length();
		next4a = true;
		for (i = 1; i <= sz; ++i)
			if (bin[sz-i] == '1')
			{
				if (next4a)
				{
					a += pow(2, i-1);
					next4a = false;
				}
				else
				{
					b += pow(2, i-1);
					next4a = true;
				}
			}
		cout << a << " " << b << endl;
	}
	return 0;
}