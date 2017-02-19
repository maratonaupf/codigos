#include<iostream>
#include<string>

using namespace std;

int main(void){
	int L;
	string com, dir;
	// pra quem nao gosta de usar scanf() e printf(),
	// isso pode deixar o cin e cout um pouco mais rapidos
	ios::sync_with_stdio(false);
	while(cin >> L, L != 0){
		dir = "+x";
		while(--L){
			cin >> com;
			if(com == "No"){
				continue;
			}
			if(dir == "+x"){
				dir = com;
			}else
			if(dir == "-x"){
				if(com == "+y") dir = "-y";
				if(com == "-y") dir = "+y";
				if(com == "+z") dir = "-z";
				if(com == "-z") dir = "+z";
			}else
			if(dir == "+y"){
				if(com == "+y") dir = "-x";
				if(com == "-y") dir = "+x";
			}else
			if(dir == "+z"){
				if(com == "+z") dir = "-x";
				if(com == "-z") dir = "+x";
			}else
			if(dir == "-y"){
				if(com == "+y") dir = "+x";
				if(com == "-y") dir = "-x";
			}else
			if(dir == "-z"){
				if(com == "+z") dir = "+x";
				if(com == "-z") dir = "-x";
			}
		}
		cout << dir << endl;
	}
	return 0;
}
