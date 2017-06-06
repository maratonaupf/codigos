/*
 * Anderson A. Fontana
 * spoj BIT - Bits Trocados
 */

#include <iostream>

using namespace std;

int resto(int &n, int div)
{
	int ret = n/div;
	n = n%div;
	return ret;
}

int main()
{
	int V, T{1}, r[3];
	while (cin >> V && V != 0)
	{
		r[0] = resto(V,50);
		r[1] = resto(V,10);
		r[2] = resto(V,5);
		// r[3] = V;
		if (T>1) cout << endl;
		cout << "Teste " << T++ << endl;
		cout << r[0] << " " << r[1] << " " << r[2] << " " << V << endl;
	}
	return 0;
}