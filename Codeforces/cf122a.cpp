/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/122/A
*/

#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int n;
    bool ans;
    vector<int> lucky = { 
        4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777 };
    while(scanf("%d", &n) != EOF){
        ans = false;
        for(int l : lucky){
            if(n % l == 0){
                ans = true;
                break;
            }
        }
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}
