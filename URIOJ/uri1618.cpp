#include<stdio.h>

int main(void){
	int N;
	int ax, ay, bx, by, cx, cy, dx, dy, rx, ry;
	scanf("%d", &N);
	while(N--){
		scanf("%d %d %d %d %d %d %d %d %d %d", 
			&ax, &ay, &bx, &by, &cx, &cy, &dx, &dy, &rx, &ry);
		printf("%d\n", rx >= ax && rx <= bx && ry >= ay && ry <= cy);
	}
	return 0;
}
