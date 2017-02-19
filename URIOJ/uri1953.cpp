#include<stdio.h>
#include<string.h>

int main(void){
	int N, mat;
	char curso[112];
	int EPR, EHD, intrusos;
	while(scanf("%d", &N) != EOF){
		EPR = EHD = intrusos = 0;
		while(N--){
			scanf("%d %s", &mat, curso);
			if(strcmp(curso, "EPR") == 0){
				EPR++;
			}
			else if(strcmp(curso, "EHD") == 0){
				EHD++;
			}
			else{
				intrusos++;
			}
		}
		printf("EPR: %d\n", EPR);
		printf("EHD: %d\n", EHD);
		printf("INTRUSOS: %d\n", intrusos);
	}
	return 0;
}
