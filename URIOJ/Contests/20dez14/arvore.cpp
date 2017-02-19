#include<cstdio>

int main(){
	int N, i, j, sp;
	while(scanf("%d", &N)!=EOF){
		sp=N>>1;
		for(i=1; i<=N; i+=2){
			for(j=0; j<sp; j++) printf(" ");
			for(j=0; j<i; j++) printf("*");
			sp--;
			printf("\n");
		}
		sp=N>>1;
		for(j=0; j<sp; j++) printf(" ");
		printf("*\n"); sp--;
		for(j=0; j<sp; j++) printf(" ");
			printf("***\n");
		
		printf("\n");
	}
	return 0;
}
