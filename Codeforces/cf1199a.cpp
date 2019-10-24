#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 112345

int main(){
    int n, x, y, i, j;
    int a[MAX];
    int ans;
    bool valid;
    while(scanf("%d %d %d", &n, &x, &y) != EOF){
        ans = -1;
        for(i = 0; i < n; i++){
            scanf("%d", a+i);
        }
        for(i = 0; i < n; i++){
            valid = true;
            for(j = max(0, i-x); j < i; j++){
                if(a[j] <= a[i])
                    valid = false;
            }
            for(j = i+1; j < min(i+y+1, n); j++)
                if(a[j] <= a[i])
                    valid = false;
            if(valid && ans == -1)
                ans = i;
        }
        printf("%d\n", ans != -1 ? ans+1 : -1);
    }
    return 0;
}
