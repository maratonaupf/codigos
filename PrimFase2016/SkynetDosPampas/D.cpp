#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;


int main(void){
	int A, B, C, D;
	vector<int> n;
	int result = -1;
	
	while(cin >> A >> B >> C >> D){;
	
		for(int i = A; i <= C; i+=A){
			n.push_back(i);
		}
		if(n.empty()){
			cout << "-1" << endl;
			exit(0);
		}
		for(int i = 0; i < (int)n.size(); i++){
			if((n[i]%B) && (D%n[i])){
				result=n[i];
				break;
			}
		}
		cout << result << endl;
		n.clear();
	}
	
	
	return 0;
}
