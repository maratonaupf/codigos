// Leonardo Deliyannis Constantin
// http://codeforces.com/problemset/problem/96/A

#include <stdio.h>
#include <string.h>
#define MAX 112

int isDangerous(const char *s){
    return strstr(s, "1111111") != NULL || strstr(s, "0000000") != NULL;
}

int main(){
    char s[MAX];
    scanf("%s", s);
    printf("%s\n", isDangerous(s) ? "YES" : "NO");
    return 0;
}
