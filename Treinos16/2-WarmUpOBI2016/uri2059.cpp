#include<stdio.h>
//#include<iostream>

//using namespace std;

int main(void){
	int p, j1, j2, r, a;
	int win;
	//while(cin >> p >> j1 >> j2 >> r >> a){
	while(scanf("%d %d %d %d %d", &p, &j1, &j2, &r, &a) != EOF){
		if(a){
			win = r+1;
		}else if(r){
			win = 1;
		}else{
			if((j1+j2) & 1){
				win = p+1;
			}else{
				win = 2-p;
			}
		}
		//cout << "Jogador " << win << " ganha!" << endl;
		printf("Jogador %d ganha!\n", win);
	}
	return 0;
}
