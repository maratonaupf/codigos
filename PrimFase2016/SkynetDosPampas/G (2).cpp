#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
char mat[3][512][512];
int brancas,pretas,n,p;
int ant,prox;
/*void mostram(int ant, int pn)
{
		for(int x=1;x<=pn;x++)
		{
			for(int y=1;y<=pn;y++)
			{
				cout << (int)mat[ant][x][y] << " ";
			}
			cout <<"Fim\n";
		}
}*/

bool cont(int ant,int x,int y, int ele)
{
	if(mat[ant][x][y]==ele)
		return true;
	if(mat[ant][x+1][y]==ele)
		return true;
	if(mat[ant][x][y+1]==ele)
		return true;
	if(mat[ant][x+1][y+1]==ele)
		return true;
	return false;
}
void bottom_up()
{
	for(int t=1;t<n;t++)
	{
		swap(ant,prox);
		int pn = n-t;
		//if(n<6)
		//	mostram(ant,pn+1);
		for(int x=1;x<=pn;x++)
		{
			for(int y=1;y<=pn;y++)
			{
				bool preto=cont(ant,x,y,1);
				bool branco=cont(ant,x,y,2);
				bool block=cont(ant,x,y,-1);
				if(block||(preto&&branco))
				{
					mat[prox][x][y]=-1;
				} else
				if(preto&&!branco)
				{
					mat[prox][x][y]=1;
					pretas++;
				} else
				if(!preto&&branco)
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
		ant=0,prox=1;
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
