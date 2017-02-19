/*
 * Anderson A. Fontana
 * Uva 10895 - Matrix Transpose
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int M, N, R, i,j,k;
	vector<vector<int>> matrix;
	vector<int> index;
	while (cin >> M >> N)
	{		
		index.assign((M>N?M:N), 0);
		matrix.assign(M, index);
		for (i = 0; i < M; ++i)
		{
			cin >> R;
			for (j = 0; j < R; ++j)
				cin >> index[j];
			for (j = 0; j < R; ++j)
				cin >> matrix[i][index[j]-1];
		}
		cout << N << ' ' << M << endl;
		for (j = 0; j < N; ++j)
		{
			R=0;
			k=0;
			for (i = 0; i < M; ++i)
				if (matrix[i][j]!=0 && ++R)
					index[k++] = i;
			cout << R;	
			for (i = 0; i < R; ++i)
				cout << ' ' << index[i]+1;
			cout << endl;
			for (i = 0; i < R; ++i)
			{
				if (i!=0) cout << ' ';
				cout << matrix[index[i]][j];
			}
			cout << endl;
		}
		index.clear();
		matrix.clear();
	}

	return 0;
}