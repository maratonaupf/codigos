#include <iostream>
#include<bitset>
#define MAX 11234


using namespace std;

bitset<MAX> lam;
bitset<MAX> obj ;


int main(){

	int l , b , x , y, k ;
	while (cin >> l >> b ){
		for(int i = 0 ; i < l ; i ++){
			cin >>  k ;
			if( k == 0 ){
				lam [k]  =  0;
			}
		
			else if( k == 1 ){
				lam [k]  =  1;
			}
		}
		for(int i = 0 ; i < l ; i ++){
			cin >>  k ;
			if( k == 0 ){
				obj [k]  =  0;
			}
			else if( k == 1 ){
				obj [k]  =  1 ;
			}
		}
		for (int i = 0; i < b; i ++)
		{
			cin >> x >> y ;
			lam[x] = !lam[x];
			lam[y] = !lam[y];
		}
		for (int i= 0 ; i < l ; i ++ )
			if (lam[i] != obj[i]){
				cout << 'N' << endl;
				break ; 
			}
		lam.set() ;
		obj.set();
	}
	return 0;
}
