#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int C1,C2,Ia,Ib,Fa,Fb;
	cin >> Ia >> Ib >> Fa >> Fb;
	if(Ia==Fa and Ib==Fb){
		cout << "0" << endl;
	}
	if(Ia==0 and Ib==0 and Fa==1 and Fb==1){
		cout << "1" << endl;
	}
	if(Ia==0 and Ib==0 and Fa==0 and Fb==1){
		cout << "2" << endl;
	}
	if(Ia==0 and Ib==0 and Fa==1 and Fb==0){
		cout << "1" << endl;
	}
	if(Ia==1 and Ib==1 and Fa==0 and Fb==0){
		cout << "1" << endl;
	}
	if(Ia==1 and Ib==1 and Fa==1 and Fb==0){
		cout << "2" << endl;
	}
	if(Ia==1 and Ib==1 and Fa==0 and Fb==1){
		cout << "1" << endl;
	}
	if(Ia==0 and Ib==1 and Fa==0 and Fb==0){
		cout << "2" << endl;
	}
	if(Ia==0 and Ib==1 and Fa==1 and Fb==0){
		cout << "1" << endl;
	}
	if(Ia==1 and Ib==0 and Fa==0 and Fb==1){
		cout << "1" << endl;
	}
	if(Ia==1 and Ib==0 and Fa==0 and Fb==0){
		cout << "1" << endl;
	}
	if(Ia==1 and Ib==0 and Fa==1 and Fb==1){
		cout << "2" << endl;
	}
	if(Ia==0 and Ib==1 and Fa==1 and Fb==1){
		cout << "1" << endl;
	}
	
	return 0;
}


