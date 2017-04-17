/*
 * Anderson A. Fontana
 * Uva 1260 - Sales
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> A;
	int T, n, i, j, aux;
	cin >> T;
	while (T-- && cin >> n)
	{
		for (i = 0; i < n && cin >> aux; ++i)
			A.push_back(aux);

		aux = 0;
		for (i = 1; i < n; ++i)
			for (j = 0; j < i; ++j)
				if (A[j] <= A[i])
					aux++;
		cout << aux << endl;
		A.clear();
	}
	return 0;
}