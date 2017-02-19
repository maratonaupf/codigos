/*
 * Anderson A. Fontana
 * Uva 793 - Network Connections
 */

#include <iostream>

using namespace std;

int FIND(int id[], int p)
{
	if(id[p] == p) return p;
	id[p] = FIND(id, id[p]);
	return id[p];
}
void UNION(int id[], int sz[], int p, int q)
{
	p = FIND(id, p);
	q = FIND(id, q);
	if (p == q)
		return;
	if (sz[p] > sz[q])
		swap(p,q);
	id[p] = q;
	sz[q] += sz[p];
}

int main()
{
	int n, comp, i,j, yes,no;
	char ch;
	bool line{false};
	cin >> n;
	while (n--)
	{
		if(line)
			cout << endl;
		else
			line = true;

		cin >> comp;
		int id[comp], sz[comp];
		for (i = 1; i <= comp; ++i)
		{
			id[i] = i;
			sz[i] = 1;
		}
		yes = no = 0;
		cin.get(ch);
		while (cin.get(ch) && ch != '\n')
		{
			cin >> i >> j;
			if (ch == 'c')
				UNION(id,sz,i,j);
			else
				if (FIND(id,i) == FIND(id,j))
					yes++;
				else
					no++;
			cin.get(ch);
		}
		cout << yes << "," << no << endl;
	}
	return 0;
}