#include<stdio.h>
#include<string.h>
#define eq(a,b) (strcmp(a,b)==0)

int main(void){	
	int col = 0, i, tam;
	char s[82];
	while(scanf("%s", s) != EOF){
		if(eq(s,"<br>")){
			putchar('\n');
			col = 0;
		}
		else
		if(eq(s,"<hr>")){
			if(col) putchar('\n');
			for(i=0; i<80; i++) putchar('-');
			putchar('\n');
			col = 0;
		}
		else{
			tam = (int) strlen(s);
			if(col + tam < 80){
				if(col){
					putchar(' ');
					col++;
				}
				col+=tam;
				printf("%s", s);
			}else{
				printf("\n%s", s);
				col = strlen(s);
			}
		}
	}
	if(col) putchar('\n');
	return 0;
}

