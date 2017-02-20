#include<stdio.h>
#include<iostream>

using namespace std;


int main(void){
	int A, B, C, D;
	int L;

	int result = -1;

	cin >> A >> B >> C >> D;

	if((C%A) || C==D || (A==C && A==B) || (A==C && A==D)){
		 cout << -1 << endl;
		 exit(0);
	}
	result=-1;
	L=C/2;
	if(result==-1 && C%B && D&C && !(C%A)){
		cout << C << endl;
		exit(0);
	}
	for(int i = A; i <= L; i+=A){
		if((i%B) && (D%i) && !(i%A) && !(C%i)){
			result=i;
			break;
		}
	}
	
	cout << result << endl;
	
	return 0;
}
