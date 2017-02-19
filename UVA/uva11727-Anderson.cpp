/*
 * Anderson A. Fontana
 * Uva 11727 - Cost Cutting
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t, i, salario[3];
	cin >> t;
	for (i = 1; i <= t; ++i)
	{
		cin >> salario[0] >> salario[1] >> salario[2];
		sort(salario, salario+3);
		cout << "Case " << i << ": " << salario[1] << endl;
	}
	return 0;
}