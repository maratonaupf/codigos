/*
 * Anderson A. Fontana
 * Uva 11926 - Multitasking
 */

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int n, m, i, j, start, end, interval, repetition, tam{1000001};
	bool conflict, task[tam];
	while (cin >> n >> m && (n!=0 || m!=0))
	{
		memset(task, 0, sizeof(task));
		conflict = false;
		for (i = 0; i < n; ++i)
		{
			cin >> start >> end;
			if (!conflict)
				for (j = start+1; j <= end; ++j)
					if (task[j])
						conflict = true;
					else
						task[j] = true;
		}

		for (i = 0; i < m; ++i)
		{
			cin >> start >> end >> interval;
			repetition = 0;
			while(!conflict && repetition < tam)
			{
				for (j = repetition+start+1; j <= repetition+end; ++j)
					if (j < tam)
					{
						if (task[j])
							conflict = true;
						else
							task[j] = true;
					}
				repetition += interval;
			}
		}

		if (conflict)
			cout << "CONFLICT" << endl;
		else
			cout << "NO CONFLICT" << endl;
	}
	return 0;
}