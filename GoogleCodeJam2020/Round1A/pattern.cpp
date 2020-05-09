/*
 * Leonardo Deliyannis Constantin
 * Google Code Jam 2020, Round 1A - Pattern Matching
 * Practice submission
*/

#include <bits/stdc++.h>
using namespace std;
#define LEN 212

string suffix(const string &l){
    int pos;
    for(pos = l.size()-1; pos >= 0; pos--){
        if(l[pos] == '*')
            break;
    }
    return l.substr(pos+1, l.size() - (pos+1));
}

string prefix(const string &l){
    int pos = l.find("*");
    return l.substr(0, pos);
}

string findSuffix(const string &l, const vector<string> &v){
    string ans = l;
    for(string s : v){
        int i = (int)l.size() - 1;
        int j = (int)s.size() - 1;
        while(i >= 0 && j >= 0){
            if(s[j] == '*') break;
            if(s[j] != l[i]){
                ans = '*';
            }
            i--;
            j--;
        }
    }
    return ans;
}

string findPrefix(const string &l, const vector<string> &v){
    string ans = l;
    for(string s : v){
        int i = 0;
        int j = 0;
        while(l[i] != '\0' && s[j] != '\0'){
            if(s[j] == '*') break;
            if(s[j] != l[i]){
                ans = '*';
            }
            i++;
            j++;
        }
    }
    return ans;
}

char cstr[LEN];

string getInfixes(const string &s){
    int first, last;
    for(first = 0; s[first] != '\0'; first++){
        if(s[first] == '*')
            break;
    }
    for(last = s.size()-1; last >= 0; last--){
        if(s[last] == '*')
            break;
    }
    if(first == last)
        return "";
    int sz = s.size() - (first+1 + (s.size()-last));
    strcpy(cstr, s.substr(first+1, sz).c_str());
    char *p;
    p = strtok(cstr, "*");
    vector<string> infixes;
    while(p != NULL){
        infixes.push_back(p);
        p = strtok(NULL, "*");
    }
    string all = "";
    for(string i : infixes){
        all += i;
    }
    return all;
}

int main(){
    int t, x, n, i;
    char aux[LEN];
    vector<string> v, m;
    scanf("%d", &t);
    for(x = 1; x <= t; x++){
        scanf("%d", &n);
        string p = "", s = "";
        string l;
        for(i = 0; i < n; i++){
            scanf(" %s", aux);
            v.push_back(aux);
            l = prefix(v[i]);
            if(l.size() > p.size())
                p = l;
            l = suffix(v[i]);
            if(l.size() > s.size())
                s = l;
            m.push_back(getInfixes(v[i]));
        }
        string pre = findPrefix(p, v);
        string suf = findSuffix(s, v);
        string ans;
        if(pre != "*" && suf != "*"){
            ans = pre;
            for(string infix : m){
                ans += infix;
            }
            ans += suf;
        }
        else ans = "*";
        printf("Case #%d: %s\n", x, ans.c_str());
        v.clear();
        m.clear();
    }
    return 0;
}
