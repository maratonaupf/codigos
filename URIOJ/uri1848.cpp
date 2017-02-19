#include<stdio.h>
#include<string.h>

int main(void) {
    int sum = 0;
    char s[8];
    while(fgets(s, 8, stdin)){
        if(strcmp(s, "caw caw") == 0){ printf("%d\n", sum); sum = 0; }
        else{
            if(s[0] == '*') sum += 4;
            if(s[1] == '*') sum += 2;
            if(s[2] == '*') sum += 1;
        }
    }
    return 0;
}
