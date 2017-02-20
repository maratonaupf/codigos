#include<stdio.h>
#include<iostream>
#include<utility>
#include<queue>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;


int vet[51234];
int main(void){
	int n;
	while(cin >> n)
	{
		for(int i=0;i<n;i++)
		{
			cin >> vet[i];
		}
		vet[0]=1;
		vet[n-1]=1;
		for(int i=1;i<n-1;i++)
		{
			if(vet[i-1]<vet[i])
			{
				vet[i]=vet[i-1]+1;
			}
			if(vet[i-1]>vet[i])
			{
				int an=i;
				while(vet[an-1]-vet[an]>0)
				{
					vet[an-1]=vet[an]+1;
					an--;
				}
			}
		}
		int maior=0;
		for(int i=0;i<n;i++)
		{
			if(vet[i]>maior)
				maior=vet[i];
		}
		cout << maior << endl;
	}
	return 0;
}
