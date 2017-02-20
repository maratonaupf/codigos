#include<stdio.h>
#include<iostream>


using namespace std;


int main(void){
	int A, B, C, D;
	int L;

	int result = -1;
	
	while(cin >> A >> B >> C >> D){;
		if((C%A)){
			 cout << -1 << endl;
			 continue;
		}
		result=-1;
		L=C/2;
		for(int i = A; i <= L; i+=A){
			if((i%B) && (D%i) && !(i%A) && !(C%i)){
				result=i;
				break;
			}
		}
		if(result==-1 && C%B && D&C && !(C%A)) result = C;
		cout << result << endl;
		
	}
	
	
	return 0;
}
