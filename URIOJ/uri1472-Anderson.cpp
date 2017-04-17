/*
 * Anderson A. Fontana
 * Uri 1472 - Triangulos
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, i, sum, aux, step;
	vector<int> space;
	vector<bool> point;
	while (cin >> N)
	{
		sum = 0;
		for (i = 0; i < N; ++i)
		{
			cin >> aux;
			space.push_back(aux);
			sum += aux;
		}

		point.assign(sum, false);

		aux = 0;
		for (i = 0; i < N; ++i)
		{
			point[aux] = true;
			aux += space[i];
		}
		
		if (sum%3!=0)
			cout << 0 << endl;
		else
		{
			step = sum/3;
			sum = 0;
			for (i = 0; i < step; ++i)
				if (point[i] && point[i+step] && point[i+step*2])
				{
					sum++;
					point[i] = point[i+step] = point[i+step*2] = false;
				}
			cout << sum << endl;
		}

		space.clear();
		point.clear();
	}
	return 0;
}