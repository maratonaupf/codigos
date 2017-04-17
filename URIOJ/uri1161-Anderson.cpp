/*
 * Anderson A. Fontana
 * Uri 1161 - Soma de Fatoriais
 */

#include <iostream>

using namespace std;

unsigned long long int fatorial (int x)
{
	if ( x == 0 ) return 1;
	return x*fatorial(x-1);
}

int main()
{
	int M, N;
	while (cin >> M >> N)
		cout << fatorial(M) + fatorial(N) << endl;
	return 0;
}