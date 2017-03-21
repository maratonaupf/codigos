#include<stdio.h>
#include<algorithm> // max(), min()

using namespace std;

int main(void){
	int ld, cd, lv, cv;
	int resp;
	while(scanf("%d %d %d %d", &ld, &cd, &lv, &cv) != EOF){
		resp = min(
			min(max(ld, cd), max(lv, cv)), 
			min(ld, cd) + min(lv, cv)
		);
		printf("%d\n", resp * resp);
	}
	return 0;
}
