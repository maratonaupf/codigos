/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/271/A
*/

#include <stdio.h>
#include <string.h>

bool hasEqualDigits(int year){
    int cnt[10];
    memset(cnt, 0, sizeof(cnt));
    while(year != 0){
        cnt[year % 10]++;
        year /= 10;
    }
    for(int i = 0; i < 10; i++)
        if(cnt[i] > 1)
            return true;
    return false;
}

int main(){
    int y;
    while(scanf("%d", &y) != EOF){
        while(hasEqualDigits(++y));
        printf("%d\n", y);
    }
    return 0;
}
