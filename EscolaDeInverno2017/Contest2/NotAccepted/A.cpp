#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
map<ii, int> DP;

struct bac
{
	int i, f;
	bac(){}
};

struct bac_corte
{
	int bi, bf, ci, cf;
};


int corta(vector<bac> v, int i, int f)
{
	if (DP.count(ii(i,f)) != 0)
		return DP[ii(i,f)];
	int ans = 0;
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		if (i > it->i && f < it->f)
			ans += 2;
		else if ((i <= it->i && f < it->f) || (i > it->i && f >= it->f))
			ans++;
	}
	return DP[ii(i,f)] = ans;
}

int main()
{
	int N, C, x, y;
	vector<bac> v;
	while(scanf("%d %d", &N, &C) != EOF){
		v.assign(N, bac());
		for (int i = 0; i < N; ++i)
		{
			scanf("%d %*d %d %*d", &x, &y);
			if (x>y)
				swap(x,y);
			v[i].i = x; v[i].f = y;
		}
		for (int i = 0; i < C; ++i)
		{
			scanf("%d %d", &x, &y);
			printf("%d\n", corta(v, x, y));
		}
		v.clear();
		DP.clear();
	}
	return 0;
}
