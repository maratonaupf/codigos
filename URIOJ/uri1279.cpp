/*
 * Leonardo Deliyannis Constantin
 * URI 1279 - Ano Bissexto ou Ano Não Bissexto
*/

#include <stdio.h>
#include <string.h>
#define MAX 1123

bool isLeapYear(const char *s){
    int year = 0;
    for(int i = strlen(s)-4; s[i]; i++){
        year *= 10;
        year += s[i] - '0';
    }
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

bool divisibleBy15(const char *s){
    int i, sum = 0;
    for(i = 0; s[i]; i++){
        sum += s[i] - '0';
    }
    return sum % 3 == 0 && (s[i-1] == '0' || s[i-1] == '5');
}

bool divisibleBy55(const char *s){
    int i, alternateSum = 0;
    for(i = 0; s[i]; i++){
        alternateSum += (i&1) ? (s[i] - '0') : -(s[i] - '0');
    }
    return alternateSum % 11 == 0 && (s[i-1] == '0' || s[i-1] == '5');
}

int main(){
    char s[MAX];
    bool leap, huluculu, bulukulu;
    bool first = true;
    while(scanf("%s", s) != EOF){
        first ? first = false : printf("\n");
        leap = huluculu = bulukulu = false;
        if(isLeapYear(s)){
            leap = true;
            printf("This is leap year.\n");
        }
        if(divisibleBy15(s)){
            huluculu = true;
            printf("This is huluculu festival year.\n");
        }
        if(leap && divisibleBy55(s)){
            bulukulu = true;
            printf("This is bulukulu festival year.\n");
        }
        if(!(leap || huluculu || bulukulu)){
            printf("This is an ordinary year.\n");
        }
    }
    return 0;
}
