#include<iostream>
#include<stack>
#define MAX 1123

using namespace std;

bool isPossible(int N, int B[]){
	int A = 1;
	//stack<int> s;
	int s[MAX];
	int topo = -1;
	
	for(int i = 0; i < N; i++){
		//if(s.empty()){
		if(topo == -1){
			//s.push(A++);
			s[++topo] = A++;
		}
		//while(s.top() != B[i]){
		while(s[topo] != B[i]){
			if(A > N){
				return false;
			}
			//s.push(A++);
			s[++topo] = A++;
		}
		//s.pop();
		topo--;
	}
	return true;
}

int main(void){
	int N, i;
	int v[MAX];
	//while(scanf("%d", &N), N != 0){
	while(cin >> N, N != 0){
		//while(scanf("%d", &v[0]), v[0] != 0){
		while(cin >> v[0], v[0] != 0){
			for(i = 1; i < N; i++){
				//scanf("%d", &v[i]);
				cin >> v[i];
			}
			
			//printf("%s\n", isPossible(N, v) ? "Yes" : "No");
			if(isPossible(N, v)){
				cout << "Yes" << endl;
			}
			else{
				cout << "No" << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
