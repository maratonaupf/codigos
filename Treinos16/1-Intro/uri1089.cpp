//#include<stdio.h>
#include<iostream>
#define MAX 11234

using namespace std;

bool ehPico(int a, int b, int c){
	return (a < b && b > c)  //MONTANHA
		|| (a > b && b < c); //VALE
	/*
	 * if((a < b && b > c) || (a > b && b < c)){
	 * 		return true;
	 * }
	 * else{
	 * 		return false;
	 * }
	 * */
}

int contaPicos(int N, int v[]){
	int picos = 0;
	for(int i = 0; i < N; i++){
		if(ehPico(v[i], v[(i+1)%N], v[(i+2)%N])){
			picos++;
		}
	}
	/*
	if(ehPico(v[N-2], v[N-1], v[0])){ 
		picos++;
	}
	if(ehPico(v[N-1], v[0], v[1])){
		picos++;
	}
	*/
	return picos;
}

int main(void){
	int N;
	int v[MAX];
	//while(scanf("%d", &N), N){
	while(cin >> N, N != 0){
		for(int i = 0; i < N; i++){
			//scanf("%d", v+i);
			//scanf("%d", &v[i]);
			cin >> v[i];
		}
		//printf("%d\n", contaPicos(N, v));
		cout << contaPicos(N, v) << endl;
	}
	return 0;
}
