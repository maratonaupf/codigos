#include<stdio.h>
#include<stdlib.h>

int main(void){
	int n, w, y1, y2;
	int ref, valid;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &w);
		ref = -1;
		valid = 1;
		while(w--){
			scanf("%d %d", &y1, &y2);
			if(ref == -1) ref = abs(y1-y2);
			if(ref != abs(y1-y2)) valid = 0;
		}
		printf("%s\n", valid ? "yes" : "no");
		if(n) printf("\n");
	}
	return 0;
}
