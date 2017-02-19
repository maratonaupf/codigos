#include<stdio.h>

typedef struct _data{
	int dia, mes;
} data;

int diasMes[13] = {
	0, 31, 28, 31, 30, 31, 30, 
	31, 31, 30, 31, 30, 31
};

int difDatas(data a, data b){
	int i, diasA = a.dia, diasB = b.dia;
	for(i = 0; i < a.mes; i++) diasA += diasMes[i];
	for(i = 0; i < b.mes; i++) diasB += diasMes[i];
	return diasB - diasA;
}

int main(void){
	data d1, d2;
	while(scanf("%d %d", &d1.dia, &d1.mes) != EOF){
		scanf("%d %d", &d2.dia, &d2.mes);
		printf("%d\n", difDatas(d1, d2));
	}
	return 0;
}
