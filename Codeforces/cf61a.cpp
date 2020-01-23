#include<stdio.h>
#define MAX 112

int main(){
    int i;
    char a[MAX], b[MAX];
    while(scanf(" %s %s", a, b) != EOF){
        for(i = 0; a[i]; i++){
            b[i] = '0' + ((a[i] - '0') ^ (b[i] - '0'));
        } 
        printf("%s\n", b);
    }
    return 0;
}
