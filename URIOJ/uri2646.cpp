/*
 * Leonardo Deliyannis Constantin
 * URI 2646 - Secret Chamber at Mount Rushmore
*/

#include <stdio.h>
#include <string.h>
#define LEN 52
#define MAX 26

bool AG[MAX][MAX];

void floydWarshall(){
    for(int k = 0; k < MAX; k++)
        for(int i = 0; i < MAX; i++)
            for(int j = 0; j < MAX; j++)
                AG[i][j] |= AG[i][k] && AG[k][j];
}

bool equals(const char *s, const char *t){
    if(strlen(s) != strlen(t))
        return false;
    for(int i = 0; s[i]; i++)
        if(!AG[s[i]-'a'][t[i]-'a'])
            return false;
    return true;
}

int main(){
    int m, n, i;
    char a, b, s[LEN], t[LEN];
    while(scanf("%d %d", &m, &n) != EOF){
        memset(AG, 0, sizeof(AG));
        for(i = 0; i < MAX; i++)
            AG[i][i] = 1;
        while(m--){
            scanf(" %c %c", &a, &b);
            AG[a-'a'][b-'a'] = 1;
        }
        floydWarshall();
        while(n--){
            scanf(" %s %s", s, t);
            printf("%s\n", equals(s, t) ? "yes" : "no");
        }
    }
    return 0;
}
