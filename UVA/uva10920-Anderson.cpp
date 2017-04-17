/*
 * Anderson A. Fontana
 * Uva 10920 - Spiral Tap
 */

#include <iostream>

using namespace std;

int main()
{
	long int sz,p, x,y, i, segt,desl;
	while (cin >> sz >> p && sz!=0 && p!=0)
	{
		x = y = sz/2+1;
		for (i = 1; i < sz; i+=2)
			if (i*i <= p && p < (i+2)*(i+2))
				break;
			else
				x = y = x+1;
		desl = p - i*i;
		segt = desl/(i+1);
		desl = desl%(i+1);
		if (p != i*i)
		{
			x++;
			if (segt == 0)
				y -= desl-1;
			else if (segt == 1)
			{
				y -= i;
				x -= desl;
			}
			else if (segt == 2)
			{
				y -= i - desl;
				x -= i+1;
			}
			else if (segt == 3)
			{
				y++;
				x = x-i+desl-1;
			}
		}
		cout << "Line = " << x << ", column = " << y << "." << endl;
	}
	return 0;
}