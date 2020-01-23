#include<stdio.h>
#define MAX 112

int main(){
    int t, k, i, ans;
    bool chg;
    char s[MAX];
    while(scanf("%d", &t) != EOF){
        while(t--){
            scanf("%d %s", &k, s);
            chg = true;
            ans = 0;
            while(chg){
                chg = false;
                for(i = k-2; i >= 0; i--){
                    if(s[i] == 'A' && s[i+1] == 'P'){
                        s[i+1] = 'A';
                        chg = true;
                    }
                }
                if(chg)
                    ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
