/*
 * Leonardo Deliyannis Constantin
 * URI 1588 - Ajude a Federação
*/

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define LEN 22

struct team{
    string name;
    int index, pts, goals, wins;
    team(){
        pts = goals = wins = 0;
    }
};

bool cmp(team a, team b){
    if(a.pts != b.pts)
        return a.pts > b.pts;
    if(a.wins != b.wins)
        return a.wins > b.wins;
    if(a.goals != b.goals)
        return a.goals > b.goals;
    return a.index < b.index;
}

int main(){
    int T, N, M, i;
    int gh, ga;
    char h[LEN], a[LEN];
    scanf("%d", &T);
    while(T--){
        scanf(" %d %d", &N, &M);
        vector<team> v(N, team());
        map<string, int> idx;
        for(i = 0; i < N; i++){
            scanf(" %s", h);
            v[i].name = h;
            v[i].index = idx[h] = i;
        }
        for(i = 0; i < M; i++){
            scanf(" %d %s %d %s", &gh, h, &ga, a);
            v[idx[h]].pts += (gh > ga) ? 3 : (gh == ga) ? 1 : 0;
            v[idx[a]].pts += (gh < ga) ? 3 : (gh == ga) ? 1 : 0;
            v[idx[h]].goals += gh;
            v[idx[a]].goals += ga;
            v[idx[h]].wins += gh > ga;
            v[idx[a]].wins += gh < ga;
        }
        sort(v.begin(), v.end(), cmp);
        for(i = 0; i < N; i++){
            printf("%s\n", v[i].name.c_str());
        }
    }
    return 0;
}
