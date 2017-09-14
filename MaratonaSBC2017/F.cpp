#include<iostream>
#include<algorithm>
using namespace std;
int vet[10000];
int main()
{
	int n,v,ult;
	cin >> n >> v;
	for(int i=0;i<n;i++) {
		cin >> vet[i];
		vet[i] = -vet[i];
	}
	sort(vet,vet+n);
	ult=vet[v-1];
	int i;
	for(i=v-1;i<n;i++) {
		if(vet[i]!=ult) {
			break;
		}
	}
	cout << i << endl;

}
