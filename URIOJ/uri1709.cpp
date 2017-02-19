#include<stdio.h>

int main(void){
	int P, cont;
	while(scanf("%d", &P) != EOF){
		cont = 0;
		int x = 1, y;
		do{ cont++;
			y = x<<1;
			if(y<=P) x = y;
			else x-= P - (x-1);
		}while(x != 1);
		printf("%d\n", cont);
	}
}
