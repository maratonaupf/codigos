#include<stdio.h>
#include<iostream>
#include<stack>
#include <vector>
#define MAX 50

using namespace std;

int main(void){
	int n=0, j=0;
	char input[MAX], output[MAX];		
	int i;
	cin >> n;
	while(n){
		stack<int> trem;
		for(i = 0; i < n; i++){
			cin >> input[i];
		}
		for(i = 0; i < n; i++){
			cin >> output[i];
		}
		i=0;
		j=0;
		while(i < n){
			trem.push(input[i]);
			cout << 'I';
			while(!trem.empty() && j < n && trem.top()==output[j]){
				trem.pop();
				cout << "R";
				j++;
			}
			i++;
		}
		if(!trem.empty()) cout << " Impossible";
		cout << endl;
			
		cin >> n;
	}
	return 0;
}

