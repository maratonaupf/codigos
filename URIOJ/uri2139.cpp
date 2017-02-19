#include<stdio.h>

int monthDays[] = {
	31, 29, 31, 30, 31, 30, 
	31, 31, 30, 31, 30, 31
};

int daysUntilXmas(int m, int d){
	int i, ret = 360 - d;
	for(i = 0; i < m-1; i++){
		ret -= monthDays[i];
	}
	return ret;
}

int main(void){
	int m, d;
	while(scanf("%d %d", &m, &d) != EOF){
		int resp = daysUntilXmas(m, d);
		if(resp > 1)
			printf("Faltam %d dias para o natal!\n", resp);
		else puts(resp == 1 ? "E vespera de natal!" : 
				resp == 0 ? "E natal!" : "Ja passou!");
	}
	return 0;
}
