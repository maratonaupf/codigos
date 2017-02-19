/*
 * Anderson A. Fontana
 * Uva 10855 - Rotated squares
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> big;
vector<vector<char>> smll;

void le(vector<vector<char>> &arr, int sz);
void rotate(vector<vector<char>> &arr, int sz);
int numOfSmalls(int n, int N);

int main()
{
	int i, N, n;
	while (cin >> N >> n && N!=0 && n!=0)
	{
		le(big,N);
		le(smll,n);
		for (i = 0; i < 4; ++i)
		{
			if (i != 0) cout << " ";
			cout << numOfSmalls(n,N);
			rotate(smll, n);
		}
		cout << endl;
		big.clear();
		smll.clear();
	}
	return 0;
}

void le(vector<vector<char>> &arr, int sz)
{
	char aux;
	vector<char> temp;
	for (int i = 0; i < sz; ++i)
	{
		temp.clear();
		for (int j = 0; j < sz; ++j)
		{
			cin >> aux;
			temp.push_back(aux);
		}
		arr.push_back(temp);
	}
}

void rotate(vector<vector<char>> &arr, int sz)
{
	vector<vector<char>> rotated;
	vector<char> temp;
	for (int i = 0; i < sz; ++i)
	{
		temp.clear();
		for (int j = sz-1; j >= 0; --j)
		{
			temp.push_back(arr[j][i]);
		}
		rotated.push_back(temp);
	}
	arr.swap(rotated);
}

bool isEqual(int x, int y, int sz)
{
	for (int i = 0; i < sz; ++i)
		for (int j = 0; j < sz; ++j)
			if (smll[i][j] != big[x+i][y+j])
				return false;
	return true;
}

int numOfSmalls(int n, int N)
{
	int cont{0}, sz=N-n;
	for (int i = 0; i <= sz; ++i)
		for (int j = 0; j <= sz; ++j)
			if (isEqual(i,j,n))
				cont++;
	return cont;
}