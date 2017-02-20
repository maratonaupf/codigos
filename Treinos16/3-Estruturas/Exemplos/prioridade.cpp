#include<stdio.h>
#include<queue>

using namespace std;

int main(void){
	priority_queue<int> fila;
	int myvalues[] = { 20, 50, 100, 70, 300, 10, 9, 1 };
	for(int i = 0; i < 8; i++){
		fila.push(-myvalues[i]);
	}
	while(!fila.empty()){
		printf("%d\n", -fila.top());
		fila.pop();
	}
	return 0;
}
