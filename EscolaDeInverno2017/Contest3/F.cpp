#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,1,1,1,-1,-1,-1}, dy[] = {1,-1,1, -1, 0, 1, -1, 0};
int vis[1001][1001], mat[1001][1001];

vector< vector<int> > G(10001);

int inRange(int x, int y)
{
	return (x >= 0 && x <= 1000 && y >= 0 && y <= 1000);
	
}
void dfs(int x, int y)
{
	int i;
	mat[x][y] = 0;
	for(i = 0; i < 8; i++)
		if(inRange(x+dx[i], y+dy[i]))
			if(mat[x+dx[i]][y+dy[i]])
			dfs(x+dx[i], y+dy[i]);
}

int main()
{
	int k, T, N, i, j, x, y, cont;
	scanf("%d", &T);
	for(k = 1; k <= T; k++)
	{
		cont = 0;
		scanf("%d", &N);
		for(i = 0; i < N; i++)
		{
			scanf("%d %d", &x, &y);
			mat[x][y] = 1;
		}
		for(i = 0; i <= 1000; i++)
			for(j = 0; j <= 1000; j++)
			{
				if(mat[i][j])
				{
					dfs(i, j);
					cont++;
				}
			}
		printf("Case %d: %d\n", k, cont);
	}
	return 0;
}
