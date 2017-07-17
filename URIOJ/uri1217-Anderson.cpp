/*
 * Anderson A. Fontana
 * Uri 1217 - Getline Two - Frutas
 */

#include <iostream>
#include <iomanip>

using namespace std;

int kgFrutas()
{
	int qtd=1;
	string s;
	cin.ignore();
	getline(cin, s);
	for ( char c : s )
		if (c == ' ')
			qtd++;
	return qtd;
}

int main()
{
	int N, kgTotal{0}, kg;
	float valTotal{0}, val;

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> val;
		valTotal += val;
		kg = kgFrutas();
		kgTotal += kg;
		cout << "day " << i << ": " << kg << " kg" << endl;
	}
	cout << fixed << setprecision(2) << kgTotal/(N*1.00) << " kg by day" << endl;
	cout << "R$ " << fixed << setprecision(2) << valTotal/N << " by day" << endl;
	return 0;
}