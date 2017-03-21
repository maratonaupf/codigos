//#include<iostream>
#include<stdio.h>
#include<string.h>
#define MAX 112
//#define DEBP //DEBug Print

//using namespace std;

int N;
int dest[MAX];
bool vis[MAX];
int dist[MAX];
int tam;

int length(int s){
	int jooj = 1;
	for(int t = dest[s]; t != s; t=dest[t]){
		vis[t] = true;
		jooj++;
	}
	return jooj;
}

int gcd(int a, int b){
	int c;
	while(b != 0){
		c = b;
		b = a%b;
		a = c;
	}
	return a;
}

int lcm(int a, int b){
	if(a == 0 && b == 0) return 0;
	return ((a / gcd(a, b)) * b);
}

int simulation(){
	int s, tempo;
	memset(vis, 0, sizeof(vis));
	memset(dist, 0, sizeof(dist));
	tam = 0;
	for(s = 1; s <= N; s++){
		if(!vis[s]){
			vis[s] = true;
			dist[tam++] = length(s);
		}
	}
	tempo = (tam > 1) ? lcm(dist[0], dist[1]) : dist[0];
	for(s = 1; s <tam; s++){
		tempo = lcm(dist[s], tempo);
	} 
	return tempo;
}

int main(void){
	int u;
	//while(cin >> N){
	while(scanf("%d", &N) != EOF){
		for(u = 1; u <= N; u++){
			//cin >> dest[u];
			scanf("%d", dest+u);
		}
		//cout << simulation() << endl;
		printf("%d\n", simulation());
	}
	return 0;
}
