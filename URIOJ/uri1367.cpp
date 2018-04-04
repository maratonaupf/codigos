/*
 * Leonardo Deliyannis Constantin
 * URI 1367 - Ajude!
*/

#include <stdio.h>
#include <map>
using namespace std;
#define MAX 11

int main(){
    int N;
    char id, s[MAX];
    int T, ac, scoreTime;
    while(scanf("%d ", &N), N != 0){
        map<char, int> penalties;
        ac = scoreTime = 0;
        while(N--){
            scanf("%c %d %s ", &id, &T, s);
            if(s[0] == 'c'){
                ac++;
                scoreTime += T + penalties[id];
            }else{
                penalties[id] += 20;
            }
        }
        printf("%d %d\n", ac, scoreTime);
    }
    return 0;
}
