/*
 * Leonardo Deliyannis Constantin
 * URI 1495 - Futebol
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, G, gp, ga, pts, i;
    while(scanf("%d %d", &N, &G) != EOF){
        vector<int> rem;
        pts = 0;
        for(i = 0; i < N; i++){
            scanf("%d %d", &gp, &ga);
            if(gp > ga) pts += 3;
            if(gp < ga) rem.push_back(ga-gp);
            if(gp == ga){
                if(G > 0){
                    G--;
                    pts += 3;
                }
                else
                    pts += 1;
            }
        }
        sort(rem.begin(), rem.end());
        for(i = 0; i < (int)rem.size(); i++){
            if(G >= rem[i]){
                pts += (G > rem[i]) ? 3 : 1;
                G -= rem[i] + 1;
            }
        }
        printf("%d\n", pts);
    }
    return 0;
}
