/*
 * Leonardo Deliyannis Constantin
 * 
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int h, m, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &h, &m);
        printf("%d\n", 1440 - (h*60 + m));
    }
    return 0;
}
