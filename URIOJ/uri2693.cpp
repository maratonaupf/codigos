/*
 * Leonardo Deliyannis Constantin
 * URI 2693 - Van
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct student{
    string name;
    char region;
    int distance;
    student(string n, char r, int d) : name(n), region(r), distance(d){}
};

bool compare(const student &a, const student &b){
    if(a.distance != b.distance)
        return a.distance < b.distance;
    if(a.region != b.region)
        return a.region < b.region;
    return a.name < b.name;
}

int main(){
    int N, d, i;
    char r;
    string s;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> N){
        vector<student> v;
        for(i = 0; i < N; i++){
            cin >> s >> r >> d;
            v.push_back(student(s, r, d));
        }
        sort(v.begin(), v.end(), compare);
        for(i = 0; i < N; i++){
            cout << v[i].name << '\n';
        }
    }
    return 0;
}
