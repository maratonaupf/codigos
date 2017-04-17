/*
 * Anderson A. Fontana
 * spoj SENHA - Proteja sua senha
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int N, i, num, index, T{0}, final[6];
	bool firstRead;
	vector<int> v;
	vector<set<int>> pass;
	set<int> auxSet;
	char letra;
	while (cin >> N && N!=0)
	{
		firstRead = true;
		while (N--)
		{
			for (i = 0; i < 10; ++i)
			{
				cin >> num;
				v.push_back(num);
			}
			
			for (i = 0; i < 6; ++i)
			{
				cin >> letra;
				index = (letra-'A')*2;
				if (firstRead)
				{
					auxSet.insert(v[index]);
					auxSet.insert(v[index+1]);
					pass.push_back(auxSet);
					auxSet.clear();
				}
				else if (!firstRead && pass[i].size() > 1)
				{
					if (pass[i].count(v[index])!=0 && pass[i].count(v[index+1])==0)
					{
						final[i] = v[index];
						pass[i].clear();
					}
					else if (pass[i].count(v[index])==0 && pass[i].count(v[index+1])!=0)
					{
						final[i] = v[index+1];
						pass[i].clear();
					}
				}
			}
			v.clear();
			firstRead = false;
		}
		cout << "Teste " << ++T << endl;
		for (i = 0; i < 6; ++i)
			cout << final[i] << ' ';
		cout << endl << endl;

		pass.clear();
	}

	return 0;
}