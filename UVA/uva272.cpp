#include<stdio.h>

int main(void){
	int c;
	bool op = true;
	while((c = getchar()) != EOF){
		if(c == '\"'){
			printf("%s", op ? "``" : "''");
			op = !op;
		}
		else putchar(c);
	}
	return 0;
}
