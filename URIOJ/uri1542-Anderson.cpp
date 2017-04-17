/*
 * Anderson A. Fontana
 * Uri 1542 - Lendo Livros
 */

#include <iostream>

using namespace std;

int main()
{
	int Q,D,P, pag;
	while(cin >> Q >> D >> P && Q!=0)
	{
		pag = D*P*Q/(P-Q);
		cout << pag << " pagina";
		if (pag != 1)
			cout << 's';
		cout << endl;
	}
	return 0;
}