#include<stdio.h>
#include<string.h>
#define MAX 71

int main(){
    int N, i, j;
    char line[MAX];
    while(scanf("%d", &N) != EOF){
        for(i = 0; i < N; i++){
            memset(line, '3', sizeof(line));
            line[i] = '1';
            line[(N-1)-i] = '2';
            line[N] = '\0';
            puts(line);
        }
    }
    return 0;
}
