#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
char mat[2][512][512];
int brancas,pretas,n,p;
int ant,prox;
void bottom_up()
{
	for(int t=1;t<=n;t++)
	{
		int pn = n-t;
		for(int x=0;x<pn;x++)
		{
			for(int y=1;y<=pn;y++)
			{
				if( mat[ant][x][y]==1&&
					mat[ant][x+1][y]==1&&
					mat[ant][x][y+1]==1&&
					mat[ant][x+1][y+1]==1)
				{
					mat[prox][x][y]=1;
					pretas++;
				} else
				if(
					mat[ant][x][y]==2&&
					mat[ant][x+1][y]==2&&
					mat[ant][x][y+1]==2&&
					mat[ant][x+1][y+1]==2)
				{
					mat[prox][x][y]=2;
					brancas++;
				} else {
					mat[prox][x][y]=0;
				}
			}
		}
	}
}

int main(void){
	while(cin >> n >> p)
	{
		int x,y;
		ant=1,prox=2;
		pretas=0,brancas=0;
		memset(mat,0,sizeof(mat));
		for(int i=0;i<p;i++)
		{
			cin >> x >> y;
			mat[prox][x][y]=1;
			pretas++;
		}
		for(int i=0;i<p;i++)
		{
			cin >> x >> y;
			mat[prox][x][y]=2;
			brancas++;
		}
		bottom_up();
		cout << pretas << " " << brancas << endl;
	}
	return 0;
}
