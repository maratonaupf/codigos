#include<stdio.h>
#include<iostream>


using namespace std;


int main(void){
	int A, B, C, D;

	int result = -1;
	
	while(cin >> A >> B >> C >> D){;
	
		for(int i = A; i <= C; i+=A){
			if((i%B) && (D%i)){
				result=i;
				break;
			}
		}
		cout << result << endl;
		
	}
	
	
	return 0;
}
